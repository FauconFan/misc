
#include "libsat.hpp"

Clause::Clause() : _litts(NULL)
{
    this->_litts = new std::vector<int> ();
}

Clause::Clause(const Clause & rhs) : _litts(NULL) {
    *this = rhs;
}

Clause::Clause(const std::vector<int> & litts) : _litts(NULL)
{
    this->_litts = new std::vector<int> (litts);
}

Clause &Clause::operator=(const Clause & rhs) {
    if (this->_litts != NULL)
        delete this->_litts;
    this->_litts = new std::vector<int> (*(rhs.getLitts()));
    return (*this);
}

bool Clause::operator==(const Clause & rhs) const {
    for (int val : *(this->_litts)) {
        if (std::find(rhs.getLitts()->begin(), rhs.getLitts()->end(), val) == rhs.getLitts()->end())
            return (false);
    }
    return (true);
}

Clause::~Clause() {
    if (this->_litts != NULL)
        delete this->_litts;
}

std::vector<int>    *Clause::getLitts() const {
    return (this->_litts);
}

ClauseType          Clause::getType() const {
    return (CLAUSE);
}

bool                Clause::contains_litt(int litt) const {
    return (std::find(this->_litts->begin(), this->_litts->end(), litt) != this->_litts->end());
}

bool                Clause::is_tautology() const {
    std::set<int>      buff;

    for (int val : *(this->_litts)) {
        if (buff.find(-val) != buff.end())
            return (true);
        buff.insert(val);
    }
    return (false);
}

void                Clause::simplify_clause() {
    std::set<int>       buff;

    for (int val : *(this->_litts)) {
        if (buff.find(val) == buff.end())
            buff.insert(val);
    }
    this->_litts->clear();
    this->_litts->assign(buff.begin(), buff.end());
}

std::ostream &operator<<(std::ostream & os, const Clause & cl) {
    std::vector<int> *litts = cl.getLitts();

    os << "Clause [";

    for (size_t i = 0; i < litts->size(); ++i) {
        if (i != 0)
            os << " ";
        os << (*litts)[i];
    }

    os << "]\n";
    return (os);
}