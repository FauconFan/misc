#ifndef RSAT_STRUCT_HPP
#define	RSAT_STRUCT_HPP

#include "libsat.hpp"

struct RSat{
	bool         is_sat {false};
	Distrib      distrib {};
	unsigned int nb_conflict {0};

	RSat()         = delete;
	virtual~RSat() = default;

	RSat(const RSat & rsat) = default;
	RSat &operator=(const RSat & rsat) = default;

	explicit RSat(bool is_sat, const Distrib & dist = Distrib(), unsigned int nb_conflict = 0);
};

#endif // ifndef RSAT_STRUCT_HPP
