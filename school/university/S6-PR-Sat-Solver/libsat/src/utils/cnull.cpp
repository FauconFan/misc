#include "libsat.hpp"

nullbuf null_obj;
wnullbuf wnull_obj;

std::ostream cnull(&null_obj);
std::wostream wcnull(&wnull_obj);
