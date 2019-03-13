#ifndef INTERFACE_CLAUSE_HPP
#define INTERFACE_CLAUSE_HPP

#include "libsat.hpp"

enum ClauseType {
    CLAUSE,
    IMPLCLAUSE,
};

class AClause
{
    public:
        virtual ~AClause() = default;

        bool operator==(const AClause & rhs) const;

        virtual ClauseType getType() const = 0;
		virtual Occ_list get_occ_list() const = 0;
        virtual bool contains_litt(int litt) const = 0;
        virtual bool is_tautology() const = 0;
        virtual Occ_list simplify_clause() = 0;
    
    protected:
        AClause() = default;

    private:
        AClause(const AClause & rhs);
        AClause &operator=(const AClause & rhs);
};

std::ostream &operator<<(std::ostream &, const AClause &);

#endif
