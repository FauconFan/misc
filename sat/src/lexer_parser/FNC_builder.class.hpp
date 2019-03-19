#ifndef FNC_BUILDER_CLASS_HPP
#define	FNC_BUILDER_CLASS_HPP

#include "sat.hpp"

class FNC_builder final
{
	public:
		FNC_builder(const FNC_builder & rhs) = delete;
		FNC_builder &operator=(const FNC_builder & rhs) = delete;
		virtual~FNC_builder();

		static FNC_builder  &get();

		void    setNbVar(int nbvar);
		void    setNbClause(int nbclause);

		void    addVar(int var);
		void    endOfClause();

		std::vector<ImplClause>  getClauses();

	private:
		FNC_builder();

		int _nb_vars {0};    // hidden
		int _nb_clauses {0}; // hidden
		std::vector<int> _vars {};
		std::vector<ImplClause> _clauses {};
};


#endif // ifndef FNC_BUILDER_CLASS_HPP
