#ifndef OCC_LIST_HPP
#define OCC_LIST_HPP

#include "libsat.hpp"

typedef std::pair<unsigned int, unsigned int> pair;
typedef std::unordered_map<unsigned int, pair> occ_list;

pair operator+ (pair r, pair l);

#endif
