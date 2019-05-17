#include "sat.hpp"

FNC_builder::FNC_builder() = default;

FNC_builder::~FNC_builder() = default;

FNC_builder &FNC_builder::get() {
	static FNC_builder instance;

	return (instance);
}

void FNC_builder::setNbVar(int nbvar) {
	this->_nb_vars = nbvar;
}

void FNC_builder::setNbClause(int nbclause) {
	this->_nb_clauses = nbclause;
}

void FNC_builder::addVar(int var) {
	this->_vars.emplace_back(var);
}

void FNC_builder::endOfClause() {
	if (this->_vars.empty() == false) {
		this->_clauses.emplace_back(Clause(this->_vars));
		this->_vars.clear();
	}
}

std::vector<Clause> FNC_builder::getClauses() {
	this->endOfClause();
	return (this->_clauses);
}
