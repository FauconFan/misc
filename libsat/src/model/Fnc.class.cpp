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

std::vector<Clause>   Fnc::get_implclauses() {
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

Occ_list Fnc::remove_duplicates() {
	Occ_list res;

	for (auto & acl : this->_clauses) {
		res += acl.remove_duplicates();
	}
	return (res);
}

void Fnc::polarity_check(Occ_list & litt_occ, Distrib & dist) {
	std::pair<std::vector<unsigned int>, std::vector<unsigned int> > p;

	while (true) {
		p = litt_occ.getSoloPolarity();
		auto pos = p.first;
		auto neg = p.second;

		// std::cout << *this;

		// std::cout << litt_occ;

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
	// std::cout << "clean... \nSimplify... done\n";

	litt_occ -= this->remove_duplicates();
	// std::cout << "Delete tautologies... done\n";
	litt_occ -= this->remove_tautologies();
	// std::cout << "New litt_occ " << litt_occ;
	// std::cout << *this;

	// Suppression si polarité unique
	// std::cout << "Polarity test\n";
	this->polarity_check(litt_occ, dist);
	// std::cout << litt_occ << "\ndone\n";

	// std::cout << *this;

	// std::cout << "end clean\n";
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

void Fnc::cut_unit_propagation(Distrib & dist) const{
	for (const auto & ac : this->_clauses) {
		ac.cut_unit_propagation(dist);
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
