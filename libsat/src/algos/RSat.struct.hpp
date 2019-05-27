#ifndef RSAT_STRUCT_HPP
#define	RSAT_STRUCT_HPP

#include "libsat.hpp"

struct RSat{
	bool         is_sat {false};
	Distrib      distrib {};
	unsigned int nb_conflict {0};
	unsigned int nb_init_clauses {0};
	unsigned int nb_learnt_clauses {0};

	RSat()         = default;
	virtual~RSat() = default;

	RSat(const RSat & rsat) = default;
	RSat &operator=(const RSat & rsat) = default;
};

std::ostream &operator<<(std::ostream &, const RSat &);

#endif // ifndef RSAT_STRUCT_HPP
