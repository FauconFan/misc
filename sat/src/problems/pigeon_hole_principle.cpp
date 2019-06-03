#include "sat.hpp"

static unsigned int convert(int N, unsigned int id_pigeon, unsigned int id_hole) {
	return (N * (id_pigeon - 1) + id_hole);
}

void    pigeon_hole_principle(int N) {
	Fnc fnc;
	std::vector<unsigned int> vec;

	std::cout << "Nb holes : " << N << std::endl;

	if (N < 2)
		return;

	vec.reserve(N);
	for (int id_pig = 1; id_pig <= N + 1; ++id_pig) {
		for (int id_hole = 1; id_hole <= N; ++id_hole) {
			vec.push_back(convert(N, id_pig, id_hole));
		}

		fnc.add_fnc(ModelBuilder::least_kb(vec, 1, true));
		vec.clear();
	}

	for (int id_hole = 1; id_hole <= N; ++id_hole) {
		for (int id_pig = 1; id_pig <= N + 1; ++id_pig) {
			vec.push_back(convert(N, id_pig, id_hole));
		}

		fnc.add_fnc(ModelBuilder::most_kb(vec, 1, true));
		vec.clear();
	}

	auto p = dpll_solve(fnc);

	if (p.is_sat()) {
		std::cout << "Found a solution\n";
		std::cout << "THAT SHOULD NEVER HAPPEND\n";
	}
	else {
		std::cout << "Has no solution\n";
		std::cout << "It's normal\n";

		std::cout << p;
	}
} // pigeon_hole_principle
