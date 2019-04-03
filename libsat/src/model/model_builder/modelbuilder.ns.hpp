#ifndef MODEL_BUILDER_NAMESPACE_HPP
#define	MODEL_BUILDER_NAMESPACE_HPP

#include "libsat.hpp"

namespace ModelBuilder {
	Fnc     least_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b);
	Fnc     most_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b);
	Fnc     eq_kb(const std::vector<unsigned int> & tab, unsigned int k, bool b);
}; // namespace ModelBuilder

#endif // ifndef MODEL_BUILDER_NAMESPACE_HPP
