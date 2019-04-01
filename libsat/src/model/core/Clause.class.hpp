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
		Occ_list                    build_occ_list() const;

		void                        remove_litt(int);

		bool                        is_tautology() const;
		bool                        is_empty_clause() const;
		int                         contains_litt(int) const;

		void                        cut_assign_other_value(unsigned int, Distrib &) const;
		bool                        cut_unit_propagation(Distrib &) const; // On suppose que la clause est nettoyée

	private:
		std::set<unsigned int> * _pos_litts {nullptr};
		std::set<unsigned int> * _neg_litts {nullptr};
};

std::ostream &operator<<(std::ostream & os, const Clause & icl);

#endif // ifndef IMPL_CLAUSE_CLASS_HPP
