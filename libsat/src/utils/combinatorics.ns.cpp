#include "libsat.hpp"

// Used in Combinatorics::choose_k_in_n
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

namespace Combinatorics {
	std::vector<std::vector<int> > all_choose_cases_k_in_n(
	  const std::vector<int> & vec,
	  unsigned int           k) {
		std::vector<std::vector<int> > res;

		if (k <= 0 || k > vec.size())
			return (res);

		std::vector<int> buff;

		combinatorics_recu(vec.begin(), vec.end(), k, buff, res);
		return (res);
	}
} // namespace Combinatorics
