#ifndef IMPL_CLAUSE_CLASS_HPP
#define IMPL_CLAUSE_CLASS_HPP

#include "libsat.hpp"

class ImplClause : public AClause
{
	public:	
		ImplClause ();
		ImplClause (const ImplClause & icl);
		ImplClause (const Clause & cl);
		ImplClause (const std::vector<int> litts);
		virtual ~ImplClause();

		ImplClause &operator=(const ImplClause & icl);
        bool operator==(const ImplClause & rhs) const;

		std::vector<unsigned int> * getPosLitts () const;
		std::vector<unsigned int> * getNegLitts () const;
		ClauseType getType() const;
		Occ_list get_occ_list () const;

		void add (int val);
		void delete_litt (int val);
		bool contains_litt (int litt) const;//Contains_litt(val) renvoit de quel coté se situe val.
		bool is_tautology () const;//Use find
		Occ_list simplify_clause ();

	private:
		std::vector<unsigned int> * _pos_litts;
		std::vector<unsigned int> * _neg_litts;
};

ImplClause * cut (const ImplClause & dest_icl, const ImplClause & src_icl, unsigned int val);

std::ostream &operator<<(std::ostream & os, const ImplClause & icl);

#endif
