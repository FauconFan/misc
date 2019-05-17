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

	nb_conflict++;

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

std::pair<bool, Distrib> dpll_solve(Fnc & fnc) {
	unsigned int nb_conflict = 0;
	INFO("DPLL algorithm")

	fnc.set_as_ready();
	INFO(fnc)

	bool res = dpll_recu(fnc, nb_conflict);

	INFO("Finale fnc\n", fnc)

	std::cout << "Nb conflict : " << nb_conflict << std::endl;
	INFO("Nb conflict : ", nb_conflict);

	fnc.set_distrib_as_finished();
	return (std::make_pair(res, fnc.get_distrib()));
}
