#ifndef FNC_CLASS_HPP
#define	FNC_CLASS_HPP

#include "libsat.hpp"

class Fnc{
	public:
		Fnc();
		Fnc(const Fnc &);
		Fnc &operator=(const Fnc &);
		explicit Fnc(const std::vector<Clause> &);
		virtual~Fnc();

		std::vector<Clause>     get_implclauses();
		Occ_list                build_occ_list() const;

		bool                    empty() const;
		bool                    has_empty_clause() const;
		bool                    contains(const Clause &); // delete later subsumption

		void                    add_clause(const Clause &);
		void                    add_fnc(const Fnc &);

		Occ_list                eval(unsigned int id, bool value);
		void                    nettoyage(Occ_list &, Distrib &); // add subsumption

		void                    cut_assign_other_value(unsigned int, Distrib &) const;
		void                    cut_unit_propagation(Distrib &) const;

		void                    display(std::ostream &) const;

	private:
		std::vector<Clause> _clauses {};

		Occ_list        remove_duplicates();
		Occ_list        remove_tautologies();
		Occ_list        remove_if_contains(int);
		void            polarity_check(Occ_list &, Distrib &);
};

std::ostream    &operator<<(std::ostream &, const Fnc &);

#endif // ifndef Fnc_CLASS_HPP
