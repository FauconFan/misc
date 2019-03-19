#include "libsat.hpp"

FNCC::FNCC() = default;

FNCC::FNCC(const FNCC & fncc) {
	*this = fncc;
}

FNCC        &FNCC::operator=(const FNCC & fnc) {
	this->_clauses = std::vector<ImplClause>(fnc._clauses);
	return (*this);
}

FNCC::FNCC(const std::vector<ImplClause> & vec) {
	this->_clauses = std::vector<ImplClause>(vec);
}

FNCC::~FNCC() = default;

Occ_list FNCC::build_occ_list() const{
	Occ_list res;

	for (const auto & acl : this->_clauses) {
		res += acl.get_occ_list();
	}
	return (res);
}

bool FNCC::empty() const{
	return (this->_clauses.empty());
}

void FNCC::add_clause(const ImplClause & acl) {
	this->_clauses.push_back(acl);
}

void FNCC::add_fnc(const FNCC & fnc) {
	this->_clauses.insert(this->_clauses.end(), fnc._clauses.begin(), fnc._clauses.end());
}

std::vector<ImplClause>   FNCC::get_implclauses() {
	return (this->_clauses);
}

Occ_list FNCC::delete_tautologies() {
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

Occ_list FNCC::simplify() {
	Occ_list res;

	for (auto & acl : this->_clauses) {
		res += acl.simplify_clause();
	}
	return (res);
}

Occ_list FNCC::delete_if_contains(int val) {
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

bool FNCC::contains(const ImplClause & acl) {
	for (const auto & ac : this->_clauses) {
		if (ac == acl)
			return (true);
	}
	return (false);
}

void FNCC::display(std::ostream & os) const{
	os << "FNC [\n";

	for (const auto & acl : this->_clauses) {
		os << "\t" << acl;
	}
	os << "]\n";
}

std::ostream &operator<<(std::ostream & os, const FNCC & fnc) {
	fnc.display(os);
	return (os);
}
