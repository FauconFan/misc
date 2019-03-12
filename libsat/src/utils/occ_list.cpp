#include "libsat.hpp"

//Faire une classe pour occ_list plutot

pair operator+ (pair r, pair l)
{
	return pair(r.first + l.first, r.second + l.second);
}

/*litt_occ operator+= (litt_occ & dest, const litt_occ & src){
	for (auto i = src.begin(); i != src.end(); i++){
		l[*i] = 
	}
}*/
