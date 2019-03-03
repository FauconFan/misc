
#ifndef FNC_BUILDER_CLASS_HPP
#define FNC_BUILDER_CLASS_HPP

#include "sat.hpp"

class FNC_builder final
{
    public:
        virtual ~FNC_builder();

        static FNC_builder  &get();

        void    setNbVar(int nbvar);
        void    setNbClause(int nbclause);

        void    addVar(int var);
        void    endOfClause();

        FNC     *getFNC();

    private:
        FNC_builder();
        FNC_builder(const FNC_builder & rhs); // Not implemented
        FNC_builder &operator=(const FNC_builder & rhs); // Not implemented

        int                     _nb_vars; // hidden
        int                     _nb_clauses; // hidden
        std::vector<int>        _vars;
        std::vector<Clause>     _clauses;
};


#endif