#include "libsat.hpp"

Fnc::Fnc() = default;

Fnc::Fnc(const Fnc & fncc) {
	*this = fncc;
}

Fnc        &Fnc::operator=(const Fnc & fnc) {
	this->_clauses = std::vector<Clause>(fnc._clauses);
	return (*this);
}

Fnc::Fnc(const std::vector<Clause> & vec) : _clauses(vec) {}

Fnc::~Fnc() = default;

Occ_list Fnc::build_occ_list() const{
	Occ_list res;

	for (const auto & acl : this->_clauses) {
		res += acl.build_occ_list();
	}
	return (res);
}

bool Fnc::empty() const{
	return (this->_clauses.empty());
}

void Fnc::add_clause(const Clause & acl) {
	this->_clauses.push_back(acl);
}

void Fnc::add_fnc(const Fnc & fnc) {
	this->_clauses.insert(this->_clauses.end(), fnc._clauses.begin(), fnc._clauses.end());
}

std::vector<Clause> Fnc::get_implclauses() {
	return (this->_clauses);
}

bool Fnc::has_empty_clause() const{
	for (const auto & cl : this->_clauses) {
		if (cl.is_empty_clause())
			return (true);
	}
	return (false);
}

Occ_list Fnc::remove_tautologies() {
	Occ_list res;

	for (auto it = this->_clauses.begin(); it != this->_clauses.end();) {
		if (it->is_tautology()) {
			res += it->build_occ_list();
			it   = this->_clauses.erase(it);
		}
		else {
			it++;
		}
	}
	return (res);
}

void Fnc::polarity_check(Occ_list & litt_occ, Distrib & dist) {
	std::pair<std::vector<unsigned int>, std::vector<unsigned int> > p;

	while (true) {
		p = litt_occ.getSoloPolarity();
		auto pos = p.first;
		auto neg = p.second;

		Logger::info() << "FNC polarity check" << * this << litt_occ;

		if (pos.empty() && neg.empty())
			break;
		for (auto i : pos) {
			dist.set(i, true);
			litt_occ -= this->remove_if_contains(i);
		}
		for (auto i : neg) {
			dist.set(i, false);
			litt_occ -= this->remove_if_contains(i);
		}
	}
}

/* Simplifier (Une seule occurence de chaque littéral dans la prémisse (conclusion))
 * Enlever les tautologie (Retirer les clauses contenant a et -a)
 * Si x a toujours une polarité négative, la retirer partout et mettre x = 0
 * Si x a toujours une polarité positive, la retirer partout et mettre x = 1
 */
void Fnc::nettoyage(Occ_list & litt_occ, Distrib & dist) {
	Logger::info() << "clean... \n";

	Logger::info() << "Delete tautologies... done\n";
	litt_occ -= this->remove_tautologies();
	Logger::info() << "New litt_occ " << litt_occ;
	Logger::info() << * this;

	// Suppression si polarité unique
	Logger::info() << "Polarity test\n";
	this->polarity_check(litt_occ, dist);
	Logger::info() << litt_occ;

	Logger::info() << * this;

	Logger::info() << "end clean\n";
}

Occ_list Fnc::remove_if_contains(int val) {
	Occ_list res;

	for (auto it = this->_clauses.begin(); it != this->_clauses.end();) {
		int litt_side = it->contains_litt(val);
		if (litt_side != 0) {
			res += it->build_occ_list();
			it   = this->_clauses.erase(it);
		}
		else {
			it++;
		}
	}
	return (res);
}

bool Fnc::contains(const Clause & acl) {
	for (const auto & ac : this->_clauses) {
		if (ac == acl)
			return (true);
	}
	return (false);
}

void Fnc::cut_assign_other_value(unsigned int val, Distrib & dist) const{
	for (const auto & ac : this->_clauses) {
		ac.cut_assign_other_value(val, dist);
	}
}

void Fnc::deduce_unit_propagation(Distrib & dist) const{
	for (const auto & ac : this->_clauses) {
		ac.deduce_unit_propagation(dist);
	}
}

bool Fnc::elim_unit_propagation(Distrib & dist, Occ_list & litt_occ) {
	std::set<int> unit_litteraux;
	int current_unit_litteral;

	while (true) {
		for (const auto & ac : this->_clauses) {
			current_unit_litteral = ac.is_unit_clause();
			if (current_unit_litteral == 0)
				continue;
			if (unit_litteraux.count(-current_unit_litteral) == 1)
				return false;

			unit_litteraux.insert(current_unit_litteral);
			Logger::info() << "Detect new unit clause : " << current_unit_litteral << "\n";
		}

		if (unit_litteraux.empty())
			return true;

		for (int litt : unit_litteraux) {
			if (litt > 0) {
				dist.set(litt, true);
				litt_occ -= this->eval(litt, true);
			}
			else if (litt < 0) {
				dist.set(-litt, false);
				litt_occ -= this->eval(-litt, false);
			}
		}
		unit_litteraux.clear();
	}
}

Occ_list Fnc::eval(unsigned int id, bool value) {
	Occ_list res;
	int side;
	Pair pval;

	side = (value) ? 1 : -1;
	pval = (value) ? Pair(0, 1) : Pair(1, 0);
	for (auto it = this->_clauses.begin(); it != this->_clauses.end();) {
		int litt_side = it->contains_litt(id);
		bool next     = true;
		if (litt_side != 0) {
			if (litt_side == side) {
				res += it->build_occ_list();
				it   = this->_clauses.erase(it);
				next = false;
			}
			else {
				res.addPair(id, pval);
				it->remove_litt(static_cast<int>(id) * -side);
			}
		}
		if (next)
			it++;
	}
	return (res);
}

void Fnc::display(std::ostream & os) const{
	os << "FNC [\n";

	for (const auto & acl : this->_clauses) {
		os << "\t" << acl;
	}
	os << "]\n";
}

std::ostream &operator<<(std::ostream & os, const Fnc & fnc) {
	fnc.display(os);
	return (os);
}
