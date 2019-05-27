#ifndef LIBSAT_HPP
#define	LIBSAT_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <exception>
#include <sstream>
#include <iomanip>
#include <optional>
#include <random>

#include "src/utils/macros.hpp"
#include "src/utils/cnull.hpp"
#include "src/utils/Logger.class.hpp"
#include "src/utils/IPair.class.hpp"
#include "src/utils/combinatorics.ns.hpp"
#include "src/utils/Graph.class.hpp"

#include "src/model/core/Clause.class.hpp"
#include "src/model/core/Occ_list.class.hpp"
#include "src/model/core/Distrib.class.hpp"
#include "src/model/core/Decision.class.hpp"
#include "src/model/core/Fnc.class.hpp"

#include "src/model/model_builder/modelbuilder.ns.hpp"

#include "src/algos/RSat.struct.hpp"
#include "src/algos/CDCL.hpp"
#include "src/algos/DPLL.hpp"
#include "src/algos/bruteforcing.hpp"
#include "src/algos/2Sat.hpp"

#endif // ifndef LIBSAT_HPP
