#include "libsat.hpp"

// static bool brutefocing_recu(Fnc fnc, Occ_list & litt_occ, Distrib & dist) {
//  Fnc copy_fnc;
//  Occ_list copy_litt_occ;
//  Distrib copy_dist;
//  unsigned int assign_value;

//  if (fnc.has_empty_clause())
//      return (false);

//  if (fnc.empty())
//      return (true);

//  copy_fnc      = Fnc(fnc);
//  copy_litt_occ = Occ_list(litt_occ);
//  copy_dist     = Distrib(dist);

//  assign_value = litt_occ.getMaxOccu();
//  Logger::info() << "assign value : " << assign_value << "\n";
//  Logger::info() << "Try true\n";

//  litt_occ -= fnc.assign(assign_value, true);
//  dist.set(assign_value, true);


//  Logger::info() << fnc;
//  Logger::info() << litt_occ;

//  if (brutefocing_recu(fnc, litt_occ, dist))
//      return (true);

//  Logger::info() << "step back (" << assign_value << ")\n";
//  Logger::info() << "Try false\n";

//  litt_occ  = copy_litt_occ;
//  dist      = copy_dist;
//  litt_occ -= copy_fnc.assign(assign_value, false);
//  dist.set(assign_value, false);

//  Logger::info() << copy_fnc;
//  Logger::info() << litt_occ;

//  return (brutefocing_recu(copy_fnc, litt_occ, dist));
// } // brutefocing_recu

std::pair<bool, Distrib> bruteforcing_solve(const Fnc & fnc) {
	// Occ_list litt_occ = Occ_list(fnc);
	// Distrib dist(litt_occ);

	// Logger::info() << "Bruteforcing algorithm\n";
	// Logger::info() << fnc << "\n";
	// Logger::info() << litt_occ << "\n";

	// bool res = brutefocing_recu(Fnc(fnc), litt_occ, dist);

	// dist.finish();

	// Logger::info() << litt_occ;
	// Logger::info() << dist;

	// return (std::make_pair(res, dist));
	(void) fnc;
	return (std::make_pair(false, Distrib()));
}
