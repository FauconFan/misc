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

		const std::vector<Clause> & get_implclauses() const;
		Occ_list                    build_occ_list() const;

		bool                        empty() const;
		bool                        has_empty_clause() const;
		bool                        is_two_fnc() const;

		void                        add_clause(const Clause &);
		void                        add_fnc(const Fnc &);

		Occ_list                    assign(unsigned int id, bool value);
		void                        nettoyage(Occ_list &, Distrib &);

		void                        deduce_unit_propagation(Distrib &) const;
		bool                        elim_unit_propagation(Distrib &, Occ_list &);

		void                        display(std::ostream &) const;

	private:
		std::vector<Clause> _clauses {};

		Occ_list        remove_tautologies();
		Occ_list        remove_if_contains(int);
		void            polarity_check(Occ_list &, Distrib &);
};

std::ostream    &operator<<(std::ostream &, const Fnc &);

#endif // ifndef Fnc_CLASS_HPP
