
#ifndef CLAUSE_CLASS_HPP
#define CLAUSE_CLASS_HPP

#include "libsat.hpp"

class Clause
{
    public:
        Clause();
        Clause(const Clause & rhs);
        Clause(const std::vector<int> & litts);
        virtual ~Clause();

        Clause &operator=(const Clause & rhs);

        std::vector<int>    *getLitts() const;

    private:
        std::vector<int>    *_litts;
};

std::ostream &operator<<(std::ostream &, const Clause &);


#endif