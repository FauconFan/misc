#include "libsat.hpp"

static bool dpll_recu(Fnc & fnc, RSat & rsat) {
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

	if (dpll_recu(fnc, rsat))
		return (true);

	INFO("step back (", assign_value, ")")
	INFO("Try false")

	fnc.unassign();

	fnc.assign(assign_value, false);
	INFO(fnc)

	if (dpll_recu(fnc, rsat))
		return (true);

	rsat.increase_conflict();

	fnc.unassign();
	return (false);
} // dpll_recu

RSat dpll_solve(Fnc & fnc) {
	RSat rsat;

	INFO("DPLL algorithm")

	fnc.set_as_ready();
	INFO(fnc)

	rsat.set_init_clauses(fnc.nb_clauses());

	bool res = dpll_recu(fnc, rsat);

	INFO("Finale fnc\n", fnc)
	INFO("Nb conflict : ", rsat.get_nb_conflict());

	fnc.set_distrib_as_finished();
	rsat.set_is_sat(res);
	rsat.set_distrib(fnc.get_distrib());
	return (rsat);
}
