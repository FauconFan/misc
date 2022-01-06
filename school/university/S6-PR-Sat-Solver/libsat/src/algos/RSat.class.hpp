#ifndef RSAT_STRUCT_HPP
#define	RSAT_STRUCT_HPP

#include "libsat.hpp"

class RSat
{
	public:
		RSat()         = default;
		virtual~RSat() = default;

		RSat(const RSat & rsat) = default;
		RSat &operator=(const RSat & rsat) = default;

		bool is_sat() const;
		const Distrib & get_distrib() const;
		unsigned int get_nb_conflict() const;
		unsigned int get_nb_conflict_tot() const;
		unsigned int get_nb_init_clauses() const;
		unsigned int get_nb_learnt_clauses() const;
		unsigned int get_nb_learnt_clauses_tot() const;
		unsigned int get_nb_forgotten_clauses() const;
		unsigned int get_nb_forgotten_clauses_tot() const;
		unsigned int get_nb_restart() const;

		void set_is_sat(bool isat);
		void set_distrib(const Distrib & dist);
		void set_init_clauses(unsigned int init_clauses);

		void increase_conflict();
		void increase_learnt_clauses();
		void increase_forgotten_clauses();

		void restart();

	private:
		bool sat {false};
		Distrib distrib {};
		unsigned int nb_conflict {0};
		unsigned int nb_conflict_tot {0};
		unsigned int nb_init_clauses {0};
		unsigned int nb_learnt_clauses {0};
		unsigned int nb_learnt_clauses_tot {0};
		unsigned int nb_forgotten_clauses {0};
		unsigned int nb_forgotten_clauses_tot {0};
		unsigned int nb_restart {0};
};

std::ostream &operator<<(std::ostream &, const RSat &);

#endif // ifndef RSAT_STRUCT_HPP
