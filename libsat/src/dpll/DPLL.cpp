#include "libsat.hpp"

static bool dpll_recu(Fnc fnc, Occ_list & litt_occ, Distrib & dist) {
	Fnc copy_fnc;
	Occ_list copy_litt_occ;
	Distrib copy_dist;
	unsigned int assign_value;

	fnc.nettoyage(litt_occ, dist);

	if (fnc.has_empty_clause())
		return (false);

	if (fnc.empty())
		return (true);

	copy_fnc      = Fnc(fnc);
	copy_litt_occ = Occ_list(litt_occ);
	copy_dist     = Distrib(dist);

	assign_value = litt_occ.getMaxOccu();
	Logger::info() << "assign value : " << assign_value << "\n";
	Logger::info() << "Try true\n";

	litt_occ -= fnc.eval(assign_value, true);
	dist.set(assign_value, true);

	Logger::info() << fnc;
	Logger::info() << litt_occ;

	if (dpll_recu(fnc, litt_occ, dist))
		return (true);

	Logger::info() << "step back (" << assign_value << ")\n";
	Logger::info() << "Try false\n";

	litt_occ  = copy_litt_occ;
	dist      = copy_dist;
	litt_occ -= copy_fnc.eval(assign_value, false);
	dist.set(assign_value, false);

	Logger::info() << copy_fnc;
	Logger::info() << litt_occ;

	return (dpll_recu(copy_fnc, litt_occ, dist));
} // dpll_recu

std::pair<bool, Distrib> dpll_solve(const Fnc & fnc) {
	Occ_list litt_occ = Occ_list(fnc);
	Distrib dist;

	Logger::info() << "DPLL algorithm\n";
	Logger::info() << fnc << "\n";
	Logger::info() << litt_occ << "\n";

	bool res = dpll_recu(Fnc(fnc), litt_occ, dist);

	Logger::info() << litt_occ;
	Logger::info() << dist;

	return (std::make_pair(res, dist));
}
