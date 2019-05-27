#include "sat.hpp"

#define	    COORD(n, i, j) ((n) * (j) + (i) + 1)

void    draw_puzzle(int size_tab, const Distrib & distrib) {
	for (int i = 0; i < size_tab; ++i) {
		for (int j = 0; j < size_tab; ++j) {
			if (distrib.get(COORD(size_tab, i, j))) {
				std::cout << "X";
			}
			else {
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}
}

void    queens_problems(int size_tab) {
	Fnc fnc;
	std::vector<unsigned int> vec;

	// Logger::disable();

	std::cout << "size of the grid : " << size_tab << "\n";

	vec.reserve(size_tab);
	for (int i = 0; i < size_tab; ++i) {
		for (int j = 0; j < size_tab; ++j)
			vec.push_back(COORD(size_tab, j, i));

		fnc.add_fnc(ModelBuilder::eq_kb(vec, 1, true));
		vec.clear();

		for (int j = 0; j < size_tab; ++j)
			vec.push_back(COORD(size_tab, i, j));

		fnc.add_fnc(ModelBuilder::eq_kb(vec, 1, true));
		vec.clear();
	}

	for (int i = -size_tab; i < size_tab; ++i) {
		for (int j = 0; j < size_tab; ++j) {
			int di = i + j;
			int dj = j;

			if (di >= 0 && di < size_tab && dj >= 0 && dj < size_tab) {
				vec.push_back(COORD(size_tab, di, dj));
			}
		}

		fnc.add_fnc(ModelBuilder::most_kb(vec, 1, true));
		vec.clear();
	}

	for (int i = 0; i < 2 * size_tab; ++i) {
		for (int j = 0; j < size_tab; ++j) {
			int di = i - j;
			int dj = j;

			if (di >= 0 && di < size_tab && dj >= 0 && dj < size_tab) {
				vec.push_back(COORD(size_tab, di, dj));
			}
		}

		fnc.add_fnc(ModelBuilder::most_kb(vec, 1, true));
		vec.clear();
	}

	// std::cout << fnc;

	auto p = cdcl_solve(fnc);

	if (p.is_sat) {
		std::cout << "Found a solution\n";
		draw_puzzle(size_tab, p.distrib);
	}
	else {
		std::cout << "Has no solution\n";
	}

	std::cout << p;
} // queens_problems
