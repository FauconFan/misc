
#ifndef FNC_CLASS_HPP
#define FNC_CLASS_HPP

#include "libsat.hpp"

class FNC
{
    public:
        FNC();
        FNC(const FNC & rhs);
        FNC(const std::vector<Clause> & cl);
        virtual ~FNC();

        FNC &operator=(const FNC & rhs);
        
        std::vector<Clause>     *getClauses() const;

    private:
        std::vector<Clause>     *_clauses;
};

std::ostream &operator<<(std::ostream &, const FNC &);


#endif