#ifndef OCC_LIST_CLASS_HPP
#define OCC_LIST_CLASS_HPP

#include "libsat.hpp"

void init_litt_occ (Occ_list & litt_occ, const std::vector<ImplClause *> fnc);

Pair &operator+= (Pair & dest, const Pair & src);
Pair &operator-= (Pair & dest, const Pair & src);
Occ_list &operator+=(Occ_list &, const Occ_list &);
Occ_list &operator-=(Occ_list &, const Occ_list &);

std::ostream &operator<<(std::ostream & os, const Pair & p);
std::ostream &operator<<(std::ostream & os, const Occ_list & ol);


#endif
