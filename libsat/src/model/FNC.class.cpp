
#include "FNC.class.hpp"

FNC::FNC() : _clauses(NULL)
{
    this->_clauses = new std::vector<Clause> ();
}

FNC::FNC(const FNC & rhs) : _clauses(NULL)
{
    *this = rhs;
}

FNC::FNC(const std::vector<Clause> & cl) : _clauses(NULL)
{
    this->_clauses = new std::vector<Clause> (cl);
}

FNC &FNC::operator=(const FNC & rhs) {
    if (this->_clauses != NULL)
        delete this->_clauses;
    this->_clauses = new std::vector<Clause> (*(rhs.getClauses()));
    return (*this);
}

FNC::~FNC() {
    if (this->_clauses != NULL)
        delete this->_clauses;
}

std::vector<Clause>     *FNC::getClauses() const {
    return (this->_clauses);
}

std::ostream &operator<<(std::ostream &os, const FNC & fnc) {
    std::vector<Clause>     *cl_vec = fnc.getClauses();

    os << "FNC [\n";
    for (size_t i = 0; i < cl_vec->size(); ++i) {
        os << "\t" << cl_vec->at(i);
    }
    os << "]\n";
    return (os);
}