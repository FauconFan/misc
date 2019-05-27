#include "libsat.hpp"

static bool bruteforce_recu(Fnc & fnc, unsigned int & nb_conflict) {
	unsigned int assign_value;

	if (fnc.has_empty_clause())
		return (false);

	if (fnc.empty())
		return (true);

	assign_value = fnc.get_occ_list().stat_max_occu();
	INFO("assign value : ", assign_value)
	INFO("Try true")

	fnc.assign(assign_value, true);

	INFO(fnc)

	if (bruteforce_recu(fnc, nb_conflict))
		return (true);

	INFO("step back (", assign_value, ")")
	INFO("Try false")

	fnc.unassign();

	fnc.assign(assign_value, false);
	INFO(fnc)

	if (bruteforce_recu(fnc, nb_conflict))
		return (true);

	nb_conflict++;

	fnc.unassign();
	return (false);
} // bruteforce_recu

RSat bruteforcing_solve(Fnc & fnc) {
	unsigned int nb_conflict;

	INFO("algorithm algorithm")

	fnc.set_as_ready();
	INFO(fnc)

	bool res = bruteforce_recu(fnc, nb_conflict);

	INFO("Finale fnc\n", fnc)

	fnc.set_distrib_as_finished();
	return (RSat(res, fnc.get_distrib(), nb_conflict));
}
