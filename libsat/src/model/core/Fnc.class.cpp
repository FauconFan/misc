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
		std::cerr << "Not yet...\n";
		return;
	}
	this->_clauses.push_back(acl);
}

void Fnc::add_fnc(const Fnc & fnc) {
	if (this->ready) {
		std::cerr << "Not yet...\n";
		return;
	}
	this->_clauses.insert(this->_clauses.end(), fnc._clauses.begin(), fnc._clauses.end());
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
		if (cl.is_empty_clause())
			return (true);
	}
	return (false);
}

bool Fnc::is_two_fnc() const{
	for (const auto & cl : this->_clauses) {
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

		Logger::info() << "FNC polarity check" << * this << this->_occ_list;

		if (pos.empty() && neg.empty())
			break;
		for (auto i : pos) {
			this->_distrib.set(i, true);
			this->add_sub_decision(SubDecision::decision_assign(i, true));
			this->set_satisfy_if_contains(i);
		}
		for (auto i : neg) {
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
	Logger::info() << "simplify... \n";

	// Suppression si polarité unique
	Logger::info() << "Polarity test\n";
	this->polarity_check();
	Logger::info() << this->_occ_list;

	Logger::info() << * this;

	Logger::info() << "end clean\n";
}

void Fnc::set_satisfy_if_contains(int val) {
	unsigned int id = -1;

	for (auto it = this->_clauses.begin(); it != this->_clauses.end(); it++) {
		id++;
		if (it->is_satisfied())
			continue;
		int litt_side = it->presence_litt(val);
		if (litt_side != 0) {
			this->_occ_list -= it->build_occ_list();
			it->set_satisfied(true);
			this->add_sub_decision(SubDecision::decision_rm_clause(id));
		}
	}
}

bool Fnc::unit_propagation() {
	std::set<int> unit_litteraux;
	int current_unit_litteral;

	while (true) {
		for (const auto & ac : this->_clauses) {
			if (ac.is_satisfied())
				continue;
			current_unit_litteral = ac.is_unit_clause();
			if (current_unit_litteral == 0)
				continue;
			if (unit_litteraux.find(-current_unit_litteral) != unit_litteraux.end()) {
				Logger::info() << "2 opposites unit clauses are presents : " << current_unit_litteral << "\n";
				return (false);
			}

			unit_litteraux.insert(current_unit_litteral);
			Logger::info() << "Detect new unit clause : " << current_unit_litteral << "\n";
		}

		if (unit_litteraux.empty())
			return (true);

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
	this->_decisions.push_front(Decision(id, value));
	this->assign_simplify(id, value);
}

void Fnc::assign_simplify(unsigned int id, bool value) {
	int side;
	Pair pval;
	unsigned int id_clause;

	side      = (value) ? 1 : -1;
	pval      = (value) ? Pair(0, 1) : Pair(1, 0);
	id_clause = -1;
	for (auto it = this->_clauses.begin(); it != this->_clauses.end(); ++it) {
		id_clause++;
		if (it->is_satisfied())
			continue;
		int litt_side = it->presence_litt(id);
		if (litt_side != 0) {
			if (litt_side == side) {
				this->_occ_list -= it->build_occ_list();
				it->set_satisfied(true);
				this->add_sub_decision(SubDecision::decision_rm_clause(id_clause));
			}
			else {
				int val = static_cast<int>(id) * -side;
				this->_occ_list.sub_pair(id, pval);
				it->remove_litt(val);
				this->add_sub_decision(SubDecision::decision_rm_litt(id_clause, val));
			}
		}
	}
}

void Fnc::unassign() {
	if (this->_decisions.empty())
		return;

	Decision last = this->_decisions.front();
	this->_decisions.pop_front();

	for (const SubDecision & sd : last.get_consequences()) {
		switch (sd.get_type()) {
			case ASSIGN:
				this->_distrib.remove(sd.u.assign.litt_id);
				break;
			case RM_CLAUSE:
				this->_clauses[sd.u.rm_clause.clause_id].set_satisfied(false);
				this->_occ_list += this->_clauses[sd.u.rm_clause.clause_id].build_occ_list();
				break;
			case RM_LITT:
				this->_clauses[sd.u.rm_litt.clause_id].add_litt(sd.u.rm_litt.litt);
				Pair p;
				if (sd.u.rm_litt.litt > 0)
					p = Pair(1, 0);
				else
					p = Pair(0, 1);
				this->_occ_list.add_pair(abs(sd.u.rm_litt.litt), p);
				break;
		}
	}
	this->_distrib.remove(last.get_variable_id());
}

void Fnc::add_sub_decision(const SubDecision & sd) {
	if (this->_decisions.empty())
		return;

	this->_decisions.front().add_subdecision(sd);
}

void Fnc::display(std::ostream & os) const{
	os << "FNC [\n";

	for (const auto & acl : this->_clauses) {
		if (acl.is_satisfied() == false)
			os << "\t" << acl;
	}
	os << this->_occ_list;
	for (const Decision & dec : this->_decisions) {
		os << dec << "\n";
	}
	os << "]\n";
}

std::ostream &operator<<(std::ostream & os, const Fnc & fnc) {
	fnc.display(os);
	return (os);
}
