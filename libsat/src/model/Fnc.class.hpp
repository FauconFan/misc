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

		bool                        empty() const;
		void                        add_clause(const Clause &);
		void                        add_fnc(const Fnc &);
		std::vector<Clause>         get_implclauses();

		Occ_list        build_occ_list() const;

		Occ_list        delete_tautologies();
		Occ_list        simplify();
		Occ_list        delete_if_contains(int);
		bool            contains(const Clause &);

		void            display(std::ostream &) const;


	private:
		std::vector<Clause> _clauses {};
};

std::ostream    &operator<<(std::ostream &, const Fnc &);

#endif // ifndef Fnc_CLASS_HPP
