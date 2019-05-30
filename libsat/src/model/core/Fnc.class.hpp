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
		size_t nb_clauses() const;

		std::optional<unsigned int> get_level_decision_assigned_variable(int) const;

		// Setters
		void add_clause(const Clause &);
		void add_falsy_clause(Clause);
		void add_fnc(const Fnc & fnc);
		void set_as_ready();
		void set_distrib_as_finished();

		// Predicates
		bool empty() const;
		bool has_empty_clause() const;
		bool is_two_fnc() const;

		// Class response to unit_propagation
		class UPresponse{
			public:
				UPresponse()  = default;
				~UPresponse() = default;
				UPresponse(const UPresponse &) = default;
				UPresponse &operator=(const UPresponse &) = default;

				// false if there is an empty clause somewhere
				bool ok {true};
				// list of all consequences in unit propagation
				std::list<std::pair<int, std::set<int> > > li_implies {};
				// the litt_id that implies the empty clause, 0 otherwise
				unsigned int litt_id {0};
		};

		// Other
		bool assign(unsigned int id, bool value);
		int unassign();
		void backjump(unsigned int level);
		void polarity_check();
		void remove_added_clause_if(const std::function<bool(const Clause &)> &);

		UPresponse unit_propagation();

		void display(std::ostream &) const;

	private:
		bool ready {false};                           // explicit
		std::vector<Clause> _clauses {};              // List of clauses
		std::set<unsigned int> _unit_clauses_id {};   // List of id of unit clauses
		Distrib _distrib;                             // variable distribution
		Occ_list _occ_list;                           // list of occurences (variables)
		std::queue<unsigned int> _free_clauses_id {}; // List of clauses that are replacable by a new one (forgotten clauses)
		unsigned int _default_nb_clauses {0};

		// List of decisions
		std::unordered_map<int, unsigned int> _map_litt_level_decision;
		std::vector<Decision> _decisions {};

		// Simplification
		void clause_satisfy_if_contains(unsigned int id_litt);
		void clause_satisfy(unsigned int id_clause);
		void litt_satisfy(unsigned int id_clause, unsigned int id_litt, bool value);

		// Returns 0 if no conflict, otherwise returns the id of the empty clause
		unsigned int assign_simplify(unsigned int id_litt, bool value);

		// Decisions utils
		void add_sub_decision(const SubDecision & sd);
};

std::ostream    &operator<<(std::ostream &, const Fnc &);

#endif // ifndef FNC_CLASS_HPP
