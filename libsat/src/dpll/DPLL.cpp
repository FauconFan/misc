#include "libsat.hpp"

static bool dpll_recu(Fnc & fnc) {
	unsigned int assign_value;

	fnc.simplify();

	if (fnc.has_empty_clause() || !fnc.unit_propagation())
		return (false);

	if (fnc.empty())
		return (true);

	assign_value = fnc.get_occ_list().stat_max_occu();
	Logger::info() << "assign value : " << assign_value << "\n";
	Logger::info() << "Try true\n";

	fnc.assign(assign_value, true);

	Logger::info() << fnc;

	if (dpll_recu(fnc))
		return (true);

	Logger::info() << "step back (" << assign_value << ")\n";
	Logger::info() << "Try false\n";

	fnc.unassign();

	fnc.assign(assign_value, false);
	Logger::info() << fnc;

	if (dpll_recu(fnc))
		return (true);

	fnc.unassign();
	return (false);
} // dpll_recu

std::pair<bool, Distrib> dpll_solve(Fnc & fnc) {
	Logger::info() << "DPLL algorithm\n";

	fnc.set_as_ready();
	Logger::info() << fnc << "\n";

	bool res = dpll_recu(fnc);

	fnc.set_distrib_as_finished();
	return (std::make_pair(res, fnc.get_distrib()));
}
