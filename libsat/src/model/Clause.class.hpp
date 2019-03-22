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

		std::vector<unsigned int> * getPosLitts() const;
		std::vector<unsigned int> * getNegLitts() const;
		Occ_list get_occ_list() const;

		int contains_litt(int) const;
		bool is_tautology() const;
		Occ_list simplify_clause();
	// bool unit_propagation(Distrib & dist) const; //On suppose que la clause est nettoyée

	private:
		std::vector<unsigned int> * _pos_litts {nullptr};
		std::vector<unsigned int> * _neg_litts {nullptr};
};

Clause cut(const Clause & icl1, const Clause & icl2, unsigned int val);

std::ostream &operator<<(std::ostream & os, const Clause & icl);

#endif // ifndef IMPL_CLAUSE_CLASS_HPP
