#include "libsat.hpp"

#define	MAX_LEARN_CLAUSE_SIZE          10
#define	RESTART_CONFLICT_INIT          1e4
#define	RESTART_CONFLICT_MULT          1.25
#define	FORGET_CLAUSE_SIZE             5
#define	FORGET_CLAUSE_APPLY_SEUIL_MULT 1

#define	BOUNDED_LEARNING_ENABLED       true
#define	RESTART_ENABLED                true

static void insert_stack(unsigned int current_level, std::stack<std::pair<unsigned int, std::pair<int,
  std::set<int> > > > & graph, std::list<std::pair<int, std::set<int> > > last_implications) {
	for (auto impl : last_implications) {
		graph.push(std::make_pair(current_level, impl));
	}
}

static void backjump_stack(unsigned int backtrack_level, std::stack<std::pair<unsigned int, std::pair<int,
  std::set<int> > > > & graph) {
	while (graph.empty() == false && graph.top().first > backtrack_level) {
		graph.pop();
	}
}

static std::pair<std::set<int>, unsigned int> get_learn(Fnc & fnc, unsigned int current_decision_level,
  std::stack<std::pair<unsigned int, std::pair<int,
  std::set<int> > > > & graph, unsigned int conflict_var) {
	std::set<int> litts_current_level;
	std::set<int> litts_others_level;
	unsigned int max_others_level;

	litts_current_level.insert(conflict_var);
	litts_current_level.insert(-conflict_var);

	INFO("conflict_var : ", conflict_var)

	max_others_level = 0;
	while (litts_current_level.size() != 1 && graph.top().first == current_decision_level) {
		std::pair<int, std::set<int> > current_impl = graph.top().second;
		if (litts_current_level.erase(current_impl.first) == 1) {
			INFO("unit clause implication ", current_impl.first)
			INFO("implies by following :")
			for (int insert_litt : current_impl.second) {
				insert_litt = -insert_litt;
				INFO("litt ", insert_litt)
				unsigned int insert_litt_level = *fnc.get_level_decision_assigned_variable(insert_litt);
				if (insert_litt_level < current_decision_level) {
					max_others_level = std::max(max_others_level, insert_litt_level);
					litts_others_level.insert(insert_litt);
				}
				else {
					litts_current_level.insert(insert_litt);
				}
			}
		}
		graph.pop();
	}

	if (litts_current_level.size() > 1) {
		WARN("Probleme cdcl not only one in current level")
	}

	litts_others_level.insert(*litts_current_level.begin());

	INFO("backjump level : ", max_others_level)
	return std::make_pair(litts_others_level, max_others_level);
} // get_learn

static bool cdcl_ite(
  Fnc          & fnc,
  RSat         & rsat,
  bool         & do_restart,
  unsigned int max_bound_conflict,
  unsigned int & limit_forget_threshold) {
	unsigned int assign_value, decision_level;
	std::stack<std::pair<unsigned int, std::pair<int, std::set<int> > > > graph;
	std::stack<bool> first_assignment;
	std::minstd_rand simple_rand;

	simple_rand.seed(time(nullptr));
	decision_level = 0;
	fnc.polarity_check();

	while (!fnc.empty()) {
		Fnc::UPresponse res;

		res = fnc.unit_propagation();
		insert_stack(decision_level, graph, res.li_implies);

		if (res.ok == false) {
			rsat.increase_conflict();
			max_bound_conflict--;
			if (decision_level == 0) {
				return (false);
			}

			(void) do_restart;
			if (RESTART_ENABLED && max_bound_conflict == 0) {
				do_restart = true;
				return (false);
			}

			std::pair<std::set<int>, unsigned int> learn = get_learn(fnc, decision_level, graph, res.litt_id);
			if (BOUNDED_LEARNING_ENABLED && learn.first.size() > MAX_LEARN_CLAUSE_SIZE) {
				int last_assignment_value;
				while (decision_level > 0 && first_assignment.top() == false) {
					decision_level--;
					fnc.unassign();
					first_assignment.pop();
				}

				if (decision_level == 0) {
					return (false);
				}

				last_assignment_value = fnc.unassign();
				first_assignment.pop();

				backjump_stack(decision_level - 1, graph);
				fnc.assign(static_cast<unsigned int>(abs(
						last_assignment_value)), (last_assignment_value > 0) ? false : true);
				first_assignment.push(false);
			}
			else {
				for (unsigned int i = 0; i < decision_level - learn.second; i++) {
					first_assignment.pop();
				}
				decision_level = learn.second;
				fnc.backjump(decision_level);
				backjump_stack(decision_level, graph);
				std::vector<int> vec_new_clause;
				for (int litt : learn.first)
					vec_new_clause.push_back(-litt);
				Clause new_clause = Clause(vec_new_clause);
				fnc.add_falsy_clause(new_clause);
				INFO(new_clause)
				rsat.increase_learnt_clauses();
				if (learn.first.size() <= FORGET_CLAUSE_SIZE)
					limit_forget_threshold++;
			}

			if (BOUNDED_LEARNING_ENABLED && fnc.nb_learnt_clauses() >= limit_forget_threshold) {
				INFO("deleting useless clause if any")
				fnc.remove_added_clause_if([&rsat](const Clause & cl) -> bool{
					if (cl.get_litts().size() > FORGET_CLAUSE_SIZE) {
						rsat.increase_forgotten_clauses();
						return (true);
					}
					return (false);
				});
			}

			INFO(fnc)
			continue;
		}

		if (fnc.empty())
			break;

		assign_value = fnc.get_occ_list().stat_max_occu();
		decision_level++;

		INFO("assign value : ", assign_value)
		INFO("Try true")

		fnc.assign(assign_value, (simple_rand() % 2 == 0) ? true : false);
		first_assignment.push(true);

		INFO(fnc)
	}

	return (true);
} // cdcl_ite

RSat cdcl_solve(Fnc & fnc) {
	RSat rsat;
	bool res;
	bool do_restart;
	unsigned int restart_conflict       = RESTART_CONFLICT_INIT;
	unsigned int limit_forget_threshold = fnc.nb_clauses() * FORGET_CLAUSE_APPLY_SEUIL_MULT;

	INFO("CDCL algorithm")

	fnc.set_as_ready();
	INFO(fnc)

	rsat.set_init_clauses(fnc.nb_clauses());

	do_restart = false;

	while (true) {
		res = cdcl_ite(fnc, rsat, do_restart, restart_conflict, limit_forget_threshold);
		if (do_restart == false)
			break;
		restart_conflict *= RESTART_CONFLICT_MULT;
		do_restart        = false;
		fnc.backjump(0);
		std::cout << "CDCL restarted " << restart_conflict << "\n";
		INFO("restarted with new restart conflict limit : ", restart_conflict)
		INFO(fnc)
		rsat.restart();
	}

	fnc.set_distrib_as_finished();
	rsat.set_is_sat(res);
	rsat.set_distrib(fnc.get_distrib());

	INFO(rsat)
	return (rsat);
} // cdcl_solve
