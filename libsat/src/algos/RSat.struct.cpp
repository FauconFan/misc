#include "libsat.hpp"

RSat::RSat(bool is_sat, const Distrib & dist, unsigned int nb_conflict)
	: is_sat(is_sat), distrib(dist), nb_conflict(nb_conflict)
{}
