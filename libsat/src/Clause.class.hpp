
#ifndef CLAUSE_CLASS_HPP
#define CLAUSE_CLASS_HPP

#include <vector>

class Clause
{
    public:
        Clause();
        Clause(const std::vector<int> & litts);
        virtual ~Clause();

        std::vector<int>    *getLitts() const;

    private:
        std::vector<int>    *_litts;
};

std::ostream &operator<<(std::ostream &, const Clause & cl);


#endif