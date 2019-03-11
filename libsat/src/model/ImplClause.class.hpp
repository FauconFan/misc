#ifndef IMPL_CLAUSE_CLASS_HPP
#define IMPL_CLAUSE_CLASS_HPP

#include "libsat.hpp"

class ImplClause
{
	public:	
		ImplClause ();
		ImplClause (const ImplClause & icl);
		ImplClause (const Clause & cl);
		ImplClause (const std::vector<int> litts);
		virtual ~ImplClause();

		ImplClause &operator=(const ImplClause & icl);

		std::vector<unsigned int> * getPosLitts () const;
		std::vector<unsigned int> * getNegLitts () const;

		bool contains_litt (int litt);
		bool equals (const ImplClause & icl);
		bool isTautology ();
		void simplify_clause (occ_list & ol);

	private:
		std::vector<unsigned int> * _pos_litts;
		std::vector<unsigned int> * _neg_litts;
};


ImplClause cut (ImplClause & dest_icl, const ImplClause & src_icl);

std::ostream &operator<<(std::ostream & os, const ImplClause & icl);

#endif
