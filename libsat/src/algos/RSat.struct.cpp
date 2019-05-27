#include "libsat.hpp"

std::ostream &operator<<(std::ostream & os, const RSat & rsat) {
	if (rsat.is_sat == false) {
		os << "UNSAT" << std::endl;
	}
	else {
		os << "SAT" << std::endl;
		size_t i = 0;

		for (auto p : rsat.distrib.get_distrib()) {
			if (i != 0)
				os << " ";
			i++;
			if (p.second == false)
				os << "-";
			os << p.first;
		}
		os << std::endl;
	}
	os << "-- Nb conflict : " << rsat.nb_conflict << std::endl;
	os << "-- Nb init clauses : " << rsat.nb_init_clauses << std::endl;
	os << "-- Nb learnt clauses : " << rsat.nb_learnt_clauses << std::endl;
	return (os);
}
