#include "libsat.hpp"

static bool dpll_recu(Fnc & fnc, unsigned int & nb_conflict) {
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

	if (dpll_recu(fnc, nb_conflict))
		return (true);

	INFO("step back (", assign_value, ")")
	INFO("Try false")

	fnc.unassign();

	fnc.assign(assign_value, false);
	INFO(fnc)

	if (dpll_recu(fnc, nb_conflict))
		return (true);

	nb_conflict++;

	fnc.unassign();
	return (false);
} // dpll_recu

RSat dpll_solve(Fnc & fnc) {
	RSat rsat;

	INFO("DPLL algorithm")

	fnc.set_as_ready();
	INFO(fnc)

	rsat.nb_init_clauses = fnc.nb_clauses();

	bool res = dpll_recu(fnc, rsat.nb_conflict);

	INFO("Finale fnc\n", fnc)
	INFO("Nb conflict : ", rsat.nb_conflict);

	fnc.set_distrib_as_finished();
	rsat.is_sat  = res;
	rsat.distrib = fnc.get_distrib();
	return (rsat);
}
