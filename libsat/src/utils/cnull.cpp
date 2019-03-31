#include "libsat.hpp"

static nullbuf null_obj;
static wnullbuf wnull_obj;

std::ostream cnull(&null_obj);
std::wostream wcnull(&wnull_obj);
