
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

Clause::~Clause() {
    if (this->_litts != NULL)
        delete this->_litts;
}

std::vector<int>    *Clause::getLitts() const {
    return (this->_litts);
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