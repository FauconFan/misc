#include "libsat.hpp"

pair operator+ (pair r, pair l)
{
	return pair(r.first + l.first, r.second + l.second);
}
