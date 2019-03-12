
#include "FNC.class.hpp"

FNC::FNC() : _clauses(NULL)
{
    this->_clauses = new std::vector<AClause *> ();
}

FNC::FNC(const FNC & rhs) : _clauses(NULL)
{
    *this = rhs;
}

FNC::FNC(const std::vector<AClause *> & cl) : _clauses(NULL)
{
    this->_clauses = new std::vector<AClause *> (cl);
}

FNC &FNC::operator=(const FNC & rhs) {
    if (this->_clauses != NULL)
        delete this->_clauses;
    this->_clauses = new std::vector<AClause *> (*(rhs.getClauses()));
    return (*this);
}

FNC::~FNC() {
    if (this->_clauses != NULL)
        delete this->_clauses;
}

std::vector<AClause *>     *FNC::getClauses() const {
    return (this->_clauses);
}

void                        FNC::delete_tautologies() {
    this->_clauses->erase(
        std::remove_if(this->_clauses->begin(), this->_clauses->end(),
                [](const AClause * acl) -> bool {return (acl->is_tautology());}),
            this->_clauses->end()
    );
}

void                        FNC::simplify() {
    for (AClause * acl : *(this->_clauses))
        acl->simplify_clause();
}

std::ostream &operator<<(std::ostream &os, const FNC & fnc) {
    std::vector<AClause *>     *cl_vec = fnc.getClauses();

    os << "FNC [\n";
    for (const AClause * ac : *cl_vec) {
        os << "\t" << *ac;
    }
    os << "]\n";
    return (os);
}