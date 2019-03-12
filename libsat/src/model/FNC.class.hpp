
#ifndef FNC_CLASS_HPP
#define FNC_CLASS_HPP

#include "libsat.hpp"

class FNC
{
    public:
        FNC();
        FNC(const FNC & rhs);
        FNC(const std::vector<AClause *> & cl);
        virtual ~FNC();

        FNC &operator=(const FNC & rhs);
        
        std::vector<AClause *>  *getClauses() const;

        void                    delete_tautologies();             
        void                    simplify();             

    private:
        std::vector<AClause *>   *_clauses;
};

std::ostream &operator<<(std::ostream &, const FNC &);


#endif