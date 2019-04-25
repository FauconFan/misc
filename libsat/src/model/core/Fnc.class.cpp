#include "libsat.hpp"

Fnc::Fnc()  = default;
Fnc::~Fnc() = default;

Fnc::Fnc(const std::vector<Clause> & vec) {
	for (const auto & cl : vec) {
		this->add_clause(cl);
	}
}

const std::vector<Clause> &Fnc::get_clauses() const{
	return (this->_clauses);
}

const Distrib & Fnc::get_distrib() const{
	return (this->_distrib);
}

const Occ_list & Fnc::get_occ_list() const{
	return (this->_occ_list);
}

void Fnc::add_clause(const Clause & acl) {
	if (this->ready) {
		WARN("Try adding clause after setting as ready")
	}
	this->_clauses.push_back(acl);
}

void Fnc::add_fnc(const Fnc & fnc) {
	if (this->ready) {
		WARN("Try adding fnc after setting as ready")
		return;
	}
	this->_clauses.insert(this->_clauses.end(), fnc._clauses.begin(), fnc._clauses.end());
}

// We suppose that the clause given is not satisified by the actual distribution, and is not reductible to an unit clause.
// Usefull in CDCL.
void Fnc::add_falsy_clause(Clause cl) {
	static const auto & func_comp = [](
		std::pair<int, unsigned int> p1,
		std::pair<int, unsigned int> p2) -> bool{
		  return (p1.second < p2.second);
	  };

	if (this->ready == false) {
		WARN("Try adding falsy clause before setting as ready")
	}
	unsigned int clause_id = this->_clauses.size();
	std::vector<std::pair<int, unsigned int> > vec;

	for (int litt : cl.build_litts()) {
		unsigned int m = -1;

		auto it = this->_map_litt_level_decision.find(-litt);
		if (it != this->_map_litt_level_decision.end())
			m = it->second;
		vec.push_back(std::make_pair(litt, m));
	}

	std::sort(vec.begin(), vec.end(), func_comp);

	for (const auto & p : vec) {
		if (p.second >= this->_decisions.size())
			break;
		cl.remove_litt(p.first);
		this->_decisions[p.second].add_subdecision(SubDecision::decision_rm_litt(clause_id, p.first));
	}
	this->_occ_list.add_clause_id(cl.build_litts(), clause_id);
}

bool Fnc::empty() const{
	for (const Clause & cl : this->_clauses) {
		if (cl.is_satisfied() == false)
			return (false);
	}
	return (true);
}

bool Fnc::has_empty_clause() const{
	for (const auto & cl : this->_clauses) {
		if (cl.is_satisfied())
			continue;
		if (cl.is_empty_clause())
			return (true);
	}
	return (false);
}

bool Fnc::is_two_fnc() const{
	for (const auto & cl : this->_clauses) {
		if (cl.is_satisfied())
			continue;
		if (cl.is_two_clause() == false)
			return (false);
	}
	return (true);
}

void Fnc::set_as_ready() {
	if (this->ready == false) {
		this->ready = true;
		this->_occ_list.set_content(this->_clauses);
		this->_distrib.set_presence_variables(this->_clauses);
	}
}

void Fnc::set_distrib_as_finished() {
	this->_distrib.finalize();
}

void Fnc::polarity_check() {
	std::pair<std::vector<unsigned int>, std::vector<unsigned int> > p;

	while (true) {
		p = this->_occ_list.build_solo_polarity();
		auto pos = p.first;
		auto neg = p.second;

		INFO("FNC polarity check", *this, this->_occ_list)

		if (pos.empty() && neg.empty())
			break;
		for (auto i : pos) {
			INFO("Polarity positive only : ", i)
			this->_distrib.set(i, true);
			this->add_sub_decision(SubDecision::decision_assign(i, true));
			this->set_satisfy_if_contains(i);
		}
		for (auto i : neg) {
			INFO("Polarity negative only : ", i)
			this->_distrib.set(i, false);
			this->add_sub_decision(SubDecision::decision_assign(i, false));
			this->set_satisfy_if_contains(i);
		}
	}
}

/* Simplifier (Une seule occurence de chaque littéral dans la prémisse (conclusion))
 * Enlever les tautologie (Retirer les clauses contenant a et -a)
 * Si x a toujours une polarité négative, la retirer partout et mettre x = 0
 * Si x a toujours une polarité positive, la retirer partout et mettre x = 1
 */
void Fnc::simplify() {
	INFO("simplify")

	// Suppression si polarité unique
	INFO("Polarity test")
	this->polarity_check();
	INFO(this->_occ_list)

	INFO(*this)

	INFO("end clean")
}

void Fnc::set_satisfy_if_contains(int val) {
	unsigned int id = -1;

	for (Clause & cl : this->_clauses) {
		id++;
		if (cl.is_satisfied())
			continue;
		int litt_side = cl.presence_litt(val);
		if (litt_side != 0) {
			this->_occ_list.remove_clause_id(cl.build_litts(), id);
			cl.set_satisfied(true);
			this->add_sub_decision(SubDecision::decision_rm_clause(id));
		}
	}
}

#define	UP_FALSE std::make_pair(false, std::list<std::pair<int, std::set<int> > >())
#define	UP_TRUE(li) std::make_pair(true, (li))

std::pair<bool, std::list<std::pair<int, std::set<int> > > > Fnc::unit_propagation() {
	std::list<std::pair<int, std::set<int> > > list_impli;
	std::set<int> unit_litteraux;
	int current_unit_litteral;

	while (true) {
		for (const Clause & ac : this->_clauses) {
			if (ac.is_satisfied())
				continue;
			current_unit_litteral = ac.is_unit_clause();
			if (current_unit_litteral == 0)
				continue;
			if (unit_litteraux.find(-current_unit_litteral) != unit_litteraux.end()) {
				INFO("2 opposites unit clauses are presents : ", current_unit_litteral)
				return (UP_FALSE);
			}

			unit_litteraux.insert(current_unit_litteral);
			list_impli.push_back(std::make_pair(current_unit_litteral, ac.get_absent_litts()));
			INFO("Detect new unit clause : ", current_unit_litteral)
		}

		if (unit_litteraux.empty()) {
			if (this->has_empty_clause())
				return (UP_FALSE);

			return (UP_TRUE(list_impli));
		}


		for (int litt : unit_litteraux) {
			if (litt > 0) {
				this->_distrib.set(litt, true);
				this->add_sub_decision(SubDecision::decision_assign(abs(litt), true));
				this->assign_simplify(litt, true);
			}
			else if (litt < 0) {
				this->_distrib.set(-litt, false);
				this->add_sub_decision(SubDecision::decision_assign(abs(litt), false));
				this->assign_simplify(-litt, false);
			}
		}
		unit_litteraux.clear();
	}
} // Fnc::unit_propagation

void Fnc::assign(unsigned int id, bool value) {
	int val = static_cast<int>(id) * (value ? 1 : -1);

	this->_map_litt_level_decision[val] = this->_decisions.size();
	this->_decisions.push_back(Decision(id, value));
	this->_distrib.set(id, value);
	this->assign_simplify(id, value);
}

void Fnc::assign_simplify(unsigned int id_litt, bool value) {
	std::set<unsigned int> rm_clauses_cid = this->_occ_list.get_pos_occu(id_litt);
	std::set<unsigned int> rm_litt_cid    = this->_occ_list.get_neg_occu(id_litt);
	int side = (value) ? 1 : -1;

	if (value == false)
		std::swap(rm_clauses_cid, rm_litt_cid);

	for (unsigned int id_clause : rm_clauses_cid) {
		Clause & cl = this->_clauses[id_clause];
		this->_occ_list.remove_clause_id(cl.build_litts(), id_clause);
		cl.set_satisfied(true);
		this->add_sub_decision(SubDecision::decision_rm_clause(id_clause));
	}

	for (unsigned int id_clause : rm_litt_cid) {
		Clause & cl = this->_clauses[id_clause];
		int val     = static_cast<int>(id_litt) * -side;
		this->_occ_list.remove_clause_id(id_litt, id_clause, !value);
		cl.remove_litt(val);
		this->add_sub_decision(SubDecision::decision_rm_litt(id_clause, val));
	}
}

void Fnc::unassign() {
	if (this->_decisions.empty())
		return;

	Decision last = this->_decisions.back();
	this->_decisions.pop_back();

	for (const SubDecision & sd : last.get_consequences()) {
		switch (sd.get_type()) {
			case ASSIGN: {
				unsigned int litt = sd.assign_get_litt();
				int val = static_cast<int>(litt) * (sd.assign_get_value() ? 1 : -1);
				this->_distrib.remove(litt);
				this->_map_litt_level_decision.erase(val);
				break;
			}
			case RM_CLAUSE: {
				auto clause_id = sd.rm_clause_get_clause_id();
				this->_clauses[clause_id].set_satisfied(false);
				this->_occ_list.add_clause_id(this->_clauses[clause_id].build_litts(), clause_id);
				break;
			}
			case RM_LITT: {
				auto clause_id = sd.rm_litt_get_clause_id();
				auto litt      = sd.rm_litt_get_litt();
				this->_clauses[clause_id].add_litt(litt);
				this->_occ_list.add_clause_id(abs(litt), clause_id, litt > 0);
				break;
			}
		}
	}
	int val = static_cast<int>(last.get_variable_id()) * (last.get_value() ? 1 : -1);
	this->_distrib.remove(last.get_variable_id());
	this->_map_litt_level_decision.erase(val);
} // Fnc::unassign

void Fnc::backjump(unsigned int level) {
	while (this->_decisions.size() > level) {
		this->unassign();
	}
}

void Fnc::add_sub_decision(const SubDecision & sd) {
	if (this->_decisions.empty())
		return;

	if (sd.get_type() == ASSIGN) {
		int val = static_cast<int>(sd.assign_get_litt()) * (sd.assign_get_value() ? 1 : -1);
		this->_map_litt_level_decision[val] = this->_decisions.size() - 1;
	}
	this->_decisions.back().add_subdecision(sd);
}

void Fnc::display(std::ostream & os) const{
	os << "FNC [\n";

	// unsigned int clause_id = 0;
	// for (const auto & acl : this->_clauses) {
	//  if (acl.is_satisfied() == false)
	//      os << "\t" << clause_id << ":" << acl;
	//  clause_id++;
	// }
	os << this->_distrib;
	os << this->_occ_list;
	for (const Decision & dec : this->_decisions) {
		os << dec << "\n";
	}
	for (const auto & p : this->_map_litt_level_decision) {
		os << "variable : " << p.first << " level : " << p.second << "\n";
	}
	os << "]\n";
}

std::ostream &operator<<(std::ostream & os, const Fnc & fnc) {
	fnc.display(os);
	return (os);
}
