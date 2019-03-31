#include "sat.hpp"

static void combinatorics_recu(
  const std::vector<int>::const_iterator & it,
  const std::vector<int>::const_iterator & et,
  int                                    remain,
  std::vector<int>                       & buffer,
  std::vector<std::vector<int> >         & res) {
	if (remain == 0) {
		res.push_back(buffer);
		return;
	}
	if (it == et)
		return;

	buffer.push_back(*it);
	combinatorics_recu(it + 1, et, remain - 1, buffer, res);
	buffer.pop_back();

	combinatorics_recu(it + 1, et, remain, buffer, res);
}

static std::vector<std::vector<int> > combinatorics(const std::vector<int> & tab, unsigned int taille) {
	std::vector<std::vector<int> > res;

	if (taille <= 0 || taille > tab.size())
		return (res);

	std::vector<int> buff;

	combinatorics_recu(tab.begin(), tab.end(), taille, buff, res);
	return (res);
}

static Fnc      least_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b) {
	Fnc fnc;
	std::vector<std::vector<int> > sub_lists;
	std::vector<int> vec;
	int factor;

	if (k == 0 || k > tab.size())
		return (fnc);

	vec.reserve(tab.size());
	factor = (b) ? 1 : -1;
	for (unsigned int i : tab) {
		vec.push_back(factor * static_cast<int>(i));
	}
	sub_lists = combinatorics(vec, tab.size() + 1 - k);

	for (const auto & cl : sub_lists) {
		fnc.add_clause(Clause(cl));
	}
	return fnc;
}

static Fnc      most_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b) {
	return (least_kb(tab, tab.size() - k, b == false));
}

static Fnc      eq_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b) {
	Fnc fnc;

	fnc.add_fnc(least_kb(tab, k, b));
	fnc.add_fnc(most_kb(tab, k, b));
	return (fnc);
}

#define	    aij(n, i, j) ((n) * (j) + (i) + 1)

void    draw_puzzle(int size_tab, const Distrib & distrib) {
	for (int i = 0; i < size_tab; ++i) {
		for (int j = 0; j < size_tab; ++j) {
			if (distrib.get(aij(size_tab, i, j))) {
				std::cout << "X";
			}
			else {
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}
}

void    queens_problems() {
	Fnc fnc;
	int size_tab;

	std::cout << "size of the grid : ";
	std::cin >> size_tab;

	for (int i = 0; i < size_tab; ++i) {
		std::vector<unsigned int> vec;

		vec.reserve(size_tab);
		for (int j = 0; j < size_tab; ++j)
			vec.push_back(aij(size_tab, j, i));

		fnc.add_fnc(eq_kb(vec, 1, true));
		vec.clear();

		for (int j = 0; j < size_tab; ++j)
			vec.push_back(aij(size_tab, i, j));

		fnc.add_fnc(eq_kb(vec, 1, true));
		vec.clear();
	}

	for (int i = -size_tab; i < size_tab; ++i) {
		std::vector<unsigned int> vec;

		for (int j = 0; j < size_tab; ++j) {
			int di = i + j;
			int dj = j;

			if (di >= 0 && di < size_tab && dj >= 0 && dj < size_tab) {
				vec.push_back(aij(size_tab, di, dj));
			}
		}

		fnc.add_fnc(most_kb(vec, 1, true));
	}

	for (int i = 0; i < 2 * size_tab; ++i) {
		std::vector<unsigned int> vec;

		for (int j = 0; j < size_tab; ++j) {
			int di = i - j;
			int dj = j;

			if (di >= 0 && di < size_tab && dj >= 0 && dj < size_tab) {
				vec.push_back(aij(size_tab, di, dj));
			}
		}

		fnc.add_fnc(most_kb(vec, 1, true));
	}

	std::cout << fnc;

	auto p = dpll_solve(fnc);

	if (p.first) {
		std::cout << "Found a solution\n";
		draw_puzzle(size_tab, p.second);
	}
	else {
		std::cout << "Has no solution\n";
	}
} // queens_problems
