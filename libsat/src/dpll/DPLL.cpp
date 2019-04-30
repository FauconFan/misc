#include "libsat.hpp"

static bool dpll_recu(Fnc & fnc) {
	unsigned int assign_value;

	INFO(fnc)

	fnc.polarity_check();

	INFO(fnc)

	if (fnc.has_empty_clause() || fnc.unit_propagation().ok == false)
		return (false);

	if (fnc.empty())
		return (true);

	assign_value = fnc.get_occ_list().stat_max_occu();
	INFO("assign value : ", assign_value)
	INFO("Try true")

	fnc.assign(assign_value, true);

	INFO(fnc)

	if (dpll_recu(fnc))
		return (true);

	INFO("step back (", assign_value, ")")
	INFO("Try false")

	fnc.unassign();

	fnc.assign(assign_value, false);
	INFO(fnc)

	if (dpll_recu(fnc))
		return (true);

	fnc.unassign();
	return (false);
} // dpll_recu

std::pair<bool, Distrib> dpll_solve(Fnc & fnc) {
	INFO("DPLL algorithm")

	fnc.set_as_ready();
	INFO(fnc)

	bool res = dpll_recu(fnc);

	INFO("Finale fnc\n", fnc)

	fnc.set_distrib_as_finished();
	return (std::make_pair(res, fnc.get_distrib()));
}
