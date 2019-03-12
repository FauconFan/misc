
#ifndef LIBSAT_HPP
#define LIBSAT_HPP

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

typedef std::unordered_map<unsigned int, bool> Distrib;
typedef std::pair<unsigned int, unsigned int> pair;
typedef std::unordered_map<unsigned int, pair> occ_list;

#include "src/utils/occ_list.hpp"

#include "src/model/AClause.class.hpp"
#include "src/model/Clause.class.hpp"
#include "src/model/ImplClause.class.hpp"
#include "src/model/FNC.namespace.hpp"

//#include "src/coupure/Coupure.hpp"

#endif
