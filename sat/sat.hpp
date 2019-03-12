
#ifndef SAT_HPP
#define SAT_HPP

#include <iostream>
#include <vector>
#include <string>

#include "libsat.hpp"
#include "src/lexer_parser/FNC_builder.class.hpp"

std::vector<AClause *>  *getInputFNC(const char * path);

#endif