#include "libsat.hpp"

Fnc::Fnc() = default;

Fnc::Fnc(const Fnc & fncc) {
	*this = fncc;
}

Fnc        &Fnc::operator=(const Fnc & fnc) {
	this->_clauses = std::vector<ImplClause>(fnc._clauses);
	return (*this);
}

Fnc::Fnc(const std::vector<ImplClause> & vec) {
	this->_clauses = std::vector<ImplClause>(vec);
}

Fnc::~Fnc() = default;

Occ_list Fnc::build_occ_list() const{
	Occ_list res;

	for (const auto & acl : this->_clauses) {
		res += acl.get_occ_list();
	}
	return (res);
}

bool Fnc::empty() const{
	return (this->_clauses.empty());
}

void Fnc::add_clause(const ImplClause & acl) {
	this->_clauses.push_back(acl);
}

void Fnc::add_fnc(const Fnc & fnc) {
	this->_clauses.insert(this->_clauses.end(), fnc._clauses.begin(), fnc._clauses.end());
}

std::vector<ImplClause>   Fnc::get_implclauses() {
	return (this->_clauses);
}

Occ_list Fnc::delete_tautologies() {
	Occ_list res;

	for (auto it = this->_clauses.begin(); it != this->_clauses.end(); ++it) {
		if (it->is_tautology()) {
			res += it->get_occ_list();
			it--;
			this->_clauses.erase(it + 1);
		}
	}
	return (res);
}

Occ_list Fnc::simplify() {
	Occ_list res;

	for (auto & acl : this->_clauses) {
		res += acl.simplify_clause();
	}
	return (res);
}

Occ_list Fnc::delete_if_contains(int val) {
	Occ_list res;

	for (auto it = this->_clauses.begin(); it != this->_clauses.end(); ++it) {
		int litt_side = it->contains_litt(val);
		if (litt_side != 0) {
			res += it->get_occ_list();
			it--;
			this->_clauses.erase(it + 1);
		}
	}
	return (res);
}

bool Fnc::contains(const ImplClause & acl) {
	for (const auto & ac : this->_clauses) {
		if (ac == acl)
			return (true);
	}
	return (false);
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
