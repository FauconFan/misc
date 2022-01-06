#include "libsat.hpp"

namespace ModelBuilder {
	Fnc     least_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b) {
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
		sub_lists = Combinatorics::all_choose_cases_k_in_n(vec, tab.size() + 1 - k);

		for (const auto & cl : sub_lists) {
			fnc.add_clause(Clause(cl));
		}
		return (fnc);
	}

	Fnc     most_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b) {
		return (least_kb(tab, tab.size() - k, b == false));
	}

	Fnc     eq_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b) {
		Fnc fnc;

		fnc.add_fnc(least_kb(tab, k, b));
		fnc.add_fnc(most_kb(tab, k, b));
		return (fnc);
	}
} // namespace ModelBuilder
