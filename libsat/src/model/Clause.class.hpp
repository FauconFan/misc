
#ifndef CLAUSE_CLASS_HPP
#define CLAUSE_CLASS_HPP

#include "libsat.hpp"

class Clause : public AClause
{
    public:
        Clause();
        Clause(const Clause & rhs);
        Clause(const std::vector<int> & litts);
        virtual ~Clause();

        Clause &operator=(const Clause & rhs);
        bool operator==(const Clause & rhs) const;

        std::vector<int>    *getLitts() const;
        ClauseType          getType() const;
		Occ_list			get_occ_list() const;
        
        int 	            contains_litt(int litt) const;
        bool                is_tautology() const;
        Occ_list                simplify_clause();

    private:
        std::vector<int>    *_litts;
};

std::ostream &operator<<(std::ostream &, const Clause &);


#endif
