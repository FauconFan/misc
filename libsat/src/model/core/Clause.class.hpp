#ifndef CLAUSE_CLASS_HPP
#define	CLAUSE_CLASS_HPP

#include "libsat.hpp"

class Clause
{
	public:
		Clause ();
		Clause (const Clause & icl);
		explicit Clause (const std::vector<int> & litts);
		virtual~Clause();

		Clause &operator=(const Clause & icl);
		bool operator==(const Clause & rhs) const;

		std::set<unsigned int> * getPosLitts() const;
		std::set<unsigned int> * getNegLitts() const;
		std::list<int>              buildLitts() const;
		Occ_list                    build_occ_list() const;

		void                        remove_litt(int);

		bool                        is_tautology() const;
		bool                        is_empty_clause() const;
		bool                        is_two_clause() const;
		int                         is_unit_clause() const;
		int                         contains_litt(int) const;
		bool                        contains_least_one_litt_and_delete_neg(std::set<int>, Occ_list &);

		void                        cut_assign_other_value(unsigned int, Distrib &) const;
		bool                        deduce_unit_propagation(Distrib &) const;

	private:
		std::set<unsigned int> * _pos_litts {nullptr};
		std::set<unsigned int> * _neg_litts {nullptr};
};

std::ostream &operator<<(std::ostream & os, const Clause & icl);

#endif // ifndef IMPL_CLAUSE_CLASS_HPP
