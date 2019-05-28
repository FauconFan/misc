#ifndef SAT_HPP
#define	SAT_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <string>

#include "libsat.hpp"
#include "src/lexer_parser/FNC_builder.class.hpp"
#include "src/lexer_parser/Formula_builder.class.hpp"
#include "src/problems/queens.hpp"
#include "src/problems/einstein.hpp"
#include "src/problems/pigeon_hole_principle.hpp"

Fnc * getInputFNC(const char * path);

#endif // ifndef SAT_HPP
