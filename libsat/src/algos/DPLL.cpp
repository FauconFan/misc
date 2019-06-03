#include "libsat.hpp"

static bool dpll_recu(Fnc & fnc, RSat & rsat, std::minstd_rand & simple_rand) {
	unsigned int assign_value;
	bool value;

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

	value = (simple_rand() % 2 == 0);

	fnc.assign(assign_value, value);

	INFO(fnc)

	if (dpll_recu(fnc, rsat, simple_rand))
		return (true);

	INFO("step back (", assign_value, ")")
	INFO("Try false")

	fnc.unassign();

	fnc.assign(assign_value, value == false);
	INFO(fnc)

	if (dpll_recu(fnc, rsat, simple_rand))
		return (true);

	rsat.increase_conflict();

	fnc.unassign();
	return (false);
} // dpll_recu

RSat dpll_solve(Fnc & fnc) {
	RSat rsat;
	std::minstd_rand simple_rand;


	simple_rand.seed(time(nullptr));
	INFO("DPLL algorithm")

	fnc.set_as_ready();
	INFO(fnc)

	rsat.set_init_clauses(fnc.nb_clauses());

	bool res = dpll_recu(fnc, rsat, simple_rand);

	INFO("Finale fnc\n", fnc)
	INFO("Nb conflict : ", rsat.get_nb_conflict());

	fnc.set_distrib_as_finished();
	rsat.set_is_sat(res);
	rsat.set_distrib(fnc.get_distrib());

	INFO(rsat)
	return (rsat);
}
