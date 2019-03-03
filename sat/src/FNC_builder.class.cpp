
#include "sat.hpp"

FNC_builder::FNC_builder()
    : _nb_vars(0), _nb_clauses(0), _vars(), _clauses()
    {}

FNC_builder::~FNC_builder() {}

FNC_builder &FNC_builder::get() {
    static FNC_builder  instance;
    return (instance);
}

void    FNC_builder::setNbVar(int nbvar) {
    this->_nb_vars = nbvar;
}

void    FNC_builder::setNbClause(int nbclause) {
    this->_nb_clauses = nbclause;
}

void    FNC_builder::addVar(int var) {
    this->_vars.push_back(var);
}

void    FNC_builder::endOfClause() {
    if (this->_vars.empty() == false) {
        this->_clauses.push_back(Clause(this->_vars));
        this->_vars.clear();
    }
}

FNC     *FNC_builder::getFNC() {
    FNC     *res = NULL;

    this->endOfClause();
    res = new FNC(this->_clauses);
    this->_clauses.clear();
    this->_vars.clear();
    return (res);
}