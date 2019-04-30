#ifndef FNC_CLASS_HPP
#define	FNC_CLASS_HPP

#include "libsat.hpp"

class Fnc
{
	public:
		Fnc();
		explicit Fnc(const std::vector<Clause> &);
		virtual~Fnc();
		Fnc(Fnc const &) = default;
		Fnc &operator=(Fnc const &) = default;

		// Getters
		const std::vector<Clause> & get_clauses() const;
		const Distrib & get_distrib() const;
		const Occ_list & get_occ_list() const;

		// Setters
		void add_clause(const Clause &);
		void add_falsy_clause(Clause);
		void add_fnc(const Fnc &);
		void set_as_ready();
		void set_distrib_as_finished();

		// Predicates
		bool empty() const;
		bool has_empty_clause() const;
		bool is_two_fnc() const;

		// Other
		void assign(unsigned int id, bool value);
		void unassign();
		void backjump(unsigned int level);
		void simplify();

		std::pair<bool, std::list<std::pair<int, std::set<int> > > > unit_propagation();

		void display(std::ostream &) const;

	private:
		bool ready {false};
		// List of clauses
		std::vector<Clause> _clauses {};
		// variable distribution
		Distrib _distrib;
		// list of occurences (variables)
		Occ_list _occ_list;

		// List of decisions
		std::unordered_map<int, unsigned int> _map_litt_level_decision;
		std::vector<Decision> _decisions {};

		// Simplification
		void set_satisfy_if_contains(int);
		void polarity_check();
		void assign_simplify(unsigned int id_litt, bool value);

		// Decisions utils
		void add_sub_decision(const SubDecision & sd);
};

std::ostream    &operator<<(std::ostream &, const Fnc &);

#endif // ifndef FNC_CLASS_HPP
