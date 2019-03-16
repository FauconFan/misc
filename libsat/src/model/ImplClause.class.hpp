#ifndef IMPL_CLAUSE_CLASS_HPP
#define	IMPL_CLAUSE_CLASS_HPP

#include "libsat.hpp"

class ImplClause: public AClause
{
	public:
		ImplClause ();
		ImplClause (const ImplClause & icl);
		explicit ImplClause (const Clause & cl);
		explicit ImplClause (const std::vector<int> litts);
		virtual~ImplClause();

		ImplClause &operator=(const ImplClause & icl);
		bool operator==(const ImplClause & rhs) const;

		std::vector<unsigned int> * getPosLitts() const;
		std::vector<unsigned int> * getNegLitts() const;
		ClauseType getType() const;
		Occ_list get_occ_list() const;

		int contains_litt(int) const;
		bool is_tautology() const;
		Occ_list simplify_clause();
	// bool unit_propagation(Distrib & dist) const; //On suppose que la clause est nettoyée


	private:
		std::vector<unsigned int> * _pos_litts;
		std::vector<unsigned int> * _neg_litts;
};

ImplClause * cut(const ImplClause & dest_icl, const ImplClause & src_icl, unsigned int val);

std::ostream &operator<<(std::ostream & os, const ImplClause & icl);

#endif // ifndef IMPL_CLAUSE_CLASS_HPP
