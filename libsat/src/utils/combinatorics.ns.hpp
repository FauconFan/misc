#ifndef COMBINATORICS_NS_HPP
#define	COMBINATORICS_NS_HPP

#include "libsat.hpp"

namespace Combinatorics {
	std::vector<std::vector<int> > all_choose_cases_k_in_n(
	  const std::vector<int> & vec,
	  unsigned int           k);
}; // namespace Combinatorics

#endif // ifndef COMBINATORICS_NS_HPP
