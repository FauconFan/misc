#ifndef INTERFACE_CLAUSE_HPP
#define INTERFACE_CLAUSE_HPP

#include "libsat.hpp"

enum ClauseType {
    CLAUSE,
    // IMPLCLAUSE,
};

class AClause
{
    public:
        AClause() = default;
        virtual ~AClause() = default;

        bool operator==(const AClause & rhs) const;

        virtual ClauseType getType() const = 0;
        virtual bool contains_litt(int litt) const = 0;
        virtual bool is_tautology() const = 0;
        virtual void simplify_clause() = 0;
    
    private:
        AClause(const AClause & rhs);
        AClause &operator=(const AClause & rhs);
};

std::ostream &operator<<(std::ostream &, const AClause &);

#endif