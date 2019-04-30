#include "libsat.hpp"

/*class UPresponse{
 *  bool ok;
 *  std::list<std::pair<int, set<int>>> li_implies;
 *  unsigned int litt;
 * }*/

struct var_assign {
	int val;
	unsigned int decision_level;

	bool operator== (const struct var_assign v) const {
		return 	abs(this->val) == abs(v.val);
	}

	bool operator< (const struct var_assign v) const {
		return abs(this->val) < abs(v.val);
	}
};


/*static void update_graph(unsigned int current_decision_level, Graph<var_assign> & ig, std::list<std::pair<int,
  std::set<int> > > implications) {

	var_assign current_vertex;
	std::optional<var_assign> search_vertex;

	for (auto impl : implications) {
		current_vertex = {impl.first, current_decision_level};
		ig.addVertex(current_vertex);
		for (int implicated_var : impl.second) {
			search_vertex = ig.findVertex({implicated_var, 0});
			if (search_vertex != std::nullopt)
				ig.addEdge(*search_vertex, current_vertex);
		}
	}
}*/


/*static std::set<int> get_learnt_clause_set(std::list<std::pair<int, std::set<int>>> last_implications, unsigned int conflict_litt){
	std::set<int> clause_set;

	for (auto it = last_implications.crbegin(); it != last_implications.crend(); it++) {
		if (static_cast<unsigned int>(abs(it->first)) == conflict_litt) {
			clause_set.insert(it->second.cbegin(), it->second.cend());
		}
	}

	return clause_set;
}

static bool exactly_one_in_decision_level(std::set<int> clause, std::list<std::pair<int, std::set<int>>> impl) {
	int nb;

	nb = 0;
	for (auto litt = clause.cbegin(); litt != clause.cend(); litt++) {
		for (auto it = impl.crbegin(); it != impl.crend(); it++) {
			if (abs(it->first) == abs(*litt)) {
				nb++;
				if (nb > 1)
					return false;
			}
		}
	}

	return nb == 1;
}*/

// current_decision_level > 0
static std::pair<std::set<int>, unsigned int> get_learn(Fnc & fnc, unsigned int current_decision_level, /*Graph<var_assign> ig, */std::list<std::pair<int, std::set<int>>> last_implications, unsigned int conflict_var) {
	std::set<int> litts_current_level;
	std::set<int> litts_others_level;
	unsigned int max_others_level;

	litts_current_level.insert(conflict_var);
	litts_current_level.insert(-conflict_var);

	INFO("conflict_var : ", conflict_var)

	max_others_level = 0;
	// tant que learnt_clause contient plus d'un élément de niveau de décision current_decision_level
	//XXX Probleme si it == last....crend()
	for (auto it = last_implications.crbegin(); litts_current_level.size() != 1 && it != last_implications.crend(); it++){
		if (litts_current_level.erase(it->first) == 1){
			INFO("unit clause implication ", it->first)
			INFO("implies by following :")
			for (int insert_litt : it->second) {
				insert_litt = -insert_litt;
				INFO("litt ", insert_litt)
				unsigned int insert_litt_level = *fnc.get_level_decision_assigned_variable(insert_litt);
				if (insert_litt_level < current_decision_level){
					max_others_level = std::max(max_others_level, insert_litt_level);
					litts_others_level.insert(insert_litt);
				}else
					litts_current_level.insert(insert_litt);
			}
		}
	}

	if (litts_current_level.size() > 1){
		WARN("Probleme cdcl not only one in current level")
	}

	litts_others_level.insert(*litts_current_level.begin());

	INFO("backjump level : ", max_others_level)
	return std::make_pair(litts_others_level, max_others_level);
}

static bool cdcl_ite(Fnc & fnc) {
	unsigned int assign_value, decision_level;

	//Graph<var_assign> igraph;

	decision_level = 0;
	fnc.polarity_check();

	while (!fnc.empty()) {
		Fnc::UPresponse res;

		res = fnc.unit_propagation();

		for (auto impl : res.li_implies){
			INFO("target : ", impl.first)
			for (int litt : impl.second){
				INFO("origins : ", litt)
			}
		}

		if (res.ok == false) {
			if (decision_level == 0)
				return (false);

			// std::pair<Clause /*&*/, int>  learn = igraph.get_learn(res.second);
			std::pair<std::set<int>, unsigned int> learn = get_learn(fnc, decision_level, /*igraph, */res.li_implies, res.litt_id);
			decision_level = learn.second;
			fnc.backjump(decision_level);
			// igraph.backjump (backtrack_level);
			std::vector<int>	vec_new_clause;
			for (int litt : learn.first)
					vec_new_clause.push_back(-litt);
			Clause new_clause = Clause (vec_new_clause);
			fnc.add_falsy_clause(new_clause);
			INFO(new_clause)
			INFO(fnc)
			continue;
		}
		else if (fnc.empty())
				break ;

		std::cout << fnc << std::endl;
		//update_graph(decision_level, igraph, res.li_implies);

		assign_value = fnc.get_occ_list().stat_max_occu();
		decision_level++;
		// igraph.add_vertex(assign_value, decision_level);

		INFO("assign value : ", assign_value)
		Logger::info() << "Try true\n";

		fnc.assign(assign_value, true);

		Logger::info() << fnc;
	}

	return (true);
} // cdcl_ite

std::pair<bool, Distrib> cdcl_solve(Fnc & fnc) {
	Logger::info() << "CDCL algorithm\n";

	fnc.set_as_ready();
	Logger::info() << fnc << "\n";

	bool res = cdcl_ite(fnc);

	fnc.set_distrib_as_finished();
	return (std::make_pair(res, fnc.get_distrib()));
}
