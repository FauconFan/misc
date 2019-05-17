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

std::optional<unsigned int> Fnc::get_level_decision_assigned_variable(int val) const{
	auto it = this->_map_litt_level_decision.find(val);

	if (it == this->_map_litt_level_decision.end())
		return (std::nullopt);

	return (std::optional<unsigned int>(it->second));
}

void Fnc::add_clause(const Clause & cl) {
	if (this->ready) {
		WARN("Try adding clause after setting as ready")
		return;
	}
	if (cl.is_unit_clause() != 0)
		this->_unit_clauses_id.insert(this->_clauses.size());
	this->_clauses.push_back(cl);
}

void Fnc::add_fnc(const Fnc & fnc) {
	if (this->ready || fnc.ready) {
		WARN("Try adding fnc after setting as ready")
		return;
	}
	for (const Clause & cl : fnc.get_clauses()) {
		if (cl.is_unit_clause() != 0)
			this->_unit_clauses_id.insert(this->_clauses.size());
		this->_clauses.push_back(cl);
	}
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
	unsigned int id_clause = this->_clauses.size();
	std::vector<std::pair<int, unsigned int> > vec;

	for (int litt : cl.get_litts()) {
		unsigned int m = -1;

		auto it = this->_map_litt_level_decision.find(-litt);
		if (it != this->_map_litt_level_decision.end())
			m = it->second;
		vec.push_back(std::make_pair(litt, m));
	}

	INFO("Adding falsy clause : ", cl)

	std::sort(vec.begin(), vec.end(), func_comp);

	INFO("printing info")

	/*for (const auto & p : vec) {
	 *  INFO("litt : ", p.first, ", level : ", p.second)
	 * }*/

	for (const auto & p : vec) {
		if (p.second > this->_decisions.size())
			break;
		cl.remove_litt(p.first);
		if (p.second > 0)
			this->_decisions[p.second - 1].add_subdecision(SubDecision::decision_rm_litt(id_clause, p.first));
	}
	this->_occ_list.add_clause_id(cl.get_litts(), id_clause);
	this->_clauses.push_back(cl);
	if (cl.is_unit_clause() != 0)
		this->_unit_clauses_id.insert(id_clause);

	/*for (int abstent_litt : cl.get_absent_litts()) {
	 *  INFO("abstent litts ", abstent_litt)
	 * }*/
} // Fnc::add_falsy_clause

void Fnc::set_as_ready() {
	if (this->ready == false) {
		this->ready = true;
		this->_occ_list.set_content(this->_clauses);
		this->_distrib.set_presence_variables(this->_clauses);
	}
	else {
		WARN("Setting fnc as ready when it is already ready");
	}
}

void Fnc::set_distrib_as_finished() {
	this->_distrib.finalize();
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

bool Fnc::assign(unsigned int id, bool value) {
	int val = static_cast<int>(id) * (value ? 1 : -1);

	this->_decisions.push_back(Decision(id, value));
	this->_map_litt_level_decision[val] = this->_decisions.size();
	this->_distrib.set(id, value);
	return (this->assign_simplify(id, value) == 0);
}

void Fnc::unassign() {
	if (this->_decisions.empty())
		return;

	const Decision & last = this->_decisions.back();

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
				auto id_clause = sd.rm_clause_get_clause_id();
				auto & cl      = this->_clauses[id_clause];
				cl.set_satisfied(false);
				this->_occ_list.add_clause_id(cl.get_litts(), id_clause);
				if (cl.is_unit_clause() != 0)
					this->_unit_clauses_id.insert(id_clause);
				break;
			}
			case RM_LITT: {
				auto id_clause = sd.rm_litt_get_clause_id();
				auto litt      = sd.rm_litt_get_litt();
				auto & cl      = this->_clauses[id_clause];
				if (cl.is_unit_clause() != 0)
					this->_unit_clauses_id.erase(id_clause);
				cl.add_litt(litt);
				this->_occ_list.add_clause_id(abs(litt), id_clause, litt > 0);
				break;
			}
		}
	}
	int val = static_cast<int>(last.get_variable_id()) * (last.get_value() ? 1 : -1);
	this->_distrib.remove(last.get_variable_id());
	this->_map_litt_level_decision.erase(val);
	this->_decisions.pop_back();
} // Fnc::unassign

void Fnc::backjump(unsigned int level) {
	while (this->_decisions.size() > level) {
		this->unassign();
	}
}

/*
 * Si x a toujours une polarité négative, la retirer partout et mettre x = 0
 * Si x a toujours une polarité positive, la retirer partout et mettre x = 1
 */
void Fnc::polarity_check() {
	INFO("polarity check")

	INFO(*this)

	std::pair<std::vector<unsigned int>, std::vector<unsigned int> > p;

	while (true) {
		p = this->_occ_list.build_solo_polarity();
		const auto & pos = p.first;
		const auto & neg = p.second;

		INFO("FNC polarity check", *this, this->_occ_list)

		if (pos.empty() && neg.empty())
			break;
		for (auto i : pos) {
			INFO("Polarity positive only : ", i)
			this->_distrib.set(i, true);
			this->add_sub_decision(SubDecision::decision_assign(i, true));
			this->clause_satisfy_if_contains(i);
		}
		for (auto i : neg) {
			INFO("Polarity negative only : ", i)
			this->_distrib.set(i, false);
			this->add_sub_decision(SubDecision::decision_assign(i, false));
			this->clause_satisfy_if_contains(i);
		}
	}
}

Fnc::UPresponse Fnc::unit_propagation() {
	UPresponse res;

	while (this->_unit_clauses_id.empty() == false) {
		unsigned int id_clause;
		int litt;
		bool val;

		id_clause = *this->_unit_clauses_id.begin();
		this->_unit_clauses_id.erase(this->_unit_clauses_id.begin());

		Clause & cl = this->_clauses[id_clause];
		litt        = cl.is_unit_clause();
		val         = litt > 0;
		res.litt_id = abs(litt);
		res.li_implies.push_back(std::make_pair(litt, cl.get_absent_litts()));
		INFO("new unit clause : ", litt);

		this->_distrib.set(res.litt_id, val);
		this->add_sub_decision(SubDecision::decision_assign(res.litt_id, val));

		unsigned int clause_id;
		if ((clause_id = this->assign_simplify(res.litt_id, val)) != 0) {
			res.ok = false;
			INFO("Clause id conflict : ", clause_id)
			auto implied = this->_clauses[clause_id].get_absent_litts();
			implied.erase(-litt);
			res.li_implies.push_back(std::make_pair(-litt, implied));
			return (res);
		}
	}

	res.litt_id = 0;
	return (res);
} // Fnc::unit_propagation

void Fnc::display(std::ostream & os) const{
	os << "FNC [\n";

	unsigned int clause_id = 0;
	for (const auto & acl : this->_clauses) {
		if (acl.is_satisfied() == false)
			os << "\t" << clause_id << ":" << acl;
		clause_id++;
	}
	os << "unit clauses : [";
	for (auto it = this->_unit_clauses_id.begin(); it != this->_unit_clauses_id.end(); ++it) {
		if (it != this->_unit_clauses_id.begin())
			os << ", ";
		os << *it;
	}
	os << "]\n";
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

void Fnc::clause_satisfy_if_contains(unsigned int id_litt) {
	unsigned int id_clause = -1;

	for (Clause & cl : this->_clauses) {
		id_clause++;
		if (cl.is_satisfied())
			continue;
		int litt_side = cl.presence_litt(id_litt);
		if (litt_side != 0) {
			this->clause_satisfy(id_clause);
		}
	}
}

void Fnc::clause_satisfy(unsigned int id_clause) {
	Clause & cl = this->_clauses[id_clause];

	if (cl.is_unit_clause() != 0)
		this->_unit_clauses_id.erase(id_clause);
	this->_occ_list.remove_clause_id(cl.get_litts(), id_clause);
	cl.set_satisfied(true);
	this->add_sub_decision(SubDecision::decision_rm_clause(id_clause));
}

void Fnc::litt_satisfy(unsigned int id_clause, unsigned int id_litt, bool value) {
	Clause & cl = this->_clauses[id_clause];
	int val     = static_cast<int>(id_litt) * (value ? -1 : 1);

	if (cl.is_unit_clause() != 0)
		this->_unit_clauses_id.erase(id_clause);
	this->_occ_list.remove_clause_id(id_litt, id_clause, !value);
	cl.remove_litt(val);
	this->add_sub_decision(SubDecision::decision_rm_litt(id_clause, val));
	if (cl.is_unit_clause() != 0)
		this->_unit_clauses_id.insert(id_clause);
}

unsigned int Fnc::assign_simplify(unsigned int id_litt, bool value) {
	std::set<unsigned int> rm_clauses_cid = this->_occ_list.get_pos_occu(id_litt);
	std::set<unsigned int> rm_litt_cid    = this->_occ_list.get_neg_occu(id_litt);

	if (value == false)
		std::swap(rm_clauses_cid, rm_litt_cid);

	for (unsigned int id_clause : rm_litt_cid) {
		this->litt_satisfy(id_clause, id_litt, value);
		if (this->_clauses[id_clause].is_empty_clause())
			return (id_clause);
	}

	for (unsigned int id_clause : rm_clauses_cid) {
		this->clause_satisfy(id_clause);
	}
	return (0);
}

void Fnc::add_sub_decision(const SubDecision & sd) {
	if (sd.get_type() == ASSIGN) {
		int val = static_cast<int>(sd.assign_get_litt()) * (sd.assign_get_value() ? 1 : -1);
		this->_map_litt_level_decision[val] = this->_decisions.size();
	}

	if (this->_decisions.empty())
		return;

	this->_decisions.back().add_subdecision(sd);
}

std::ostream &operator<<(std::ostream & os, const Fnc & fnc) {
	fnc.display(os);
	return (os);
}
