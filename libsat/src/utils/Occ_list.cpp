#include "libsat.hpp"

//Faire une classe pour occ_list plutot

void init_litt_occ (Occ_list & litt_occ, const std::vector<ImplClause *> fnc){
	std::vector<unsigned int> pos_litts, neg_litts;

	for (auto i = fnc.begin(); i != fnc.end(); i++){
		pos_litts = *((*i)->getPosLitts());

		for (auto j = pos_litts.begin(); j != pos_litts.end(); j++){
			litt_occ[*j] += Pair(1, 0);
		}

		neg_litts = *((*i)->getNegLitts());

		for (auto j = neg_litts.begin(); j < neg_litts.end(); j++){
			litt_occ[*j] += Pair(0, 1);
		}
	}
}


Pair & operator+= (Pair & dest, const Pair & src)
{
	dest.first += src.first;
	dest.second += src.second;

	return dest;
}

Pair & operator-= (Pair & dest, const Pair & src)
{
	dest.first -= src.first;
	dest.second -= src.second;

	return dest;
}

bool operator== (const Pair & p1, const Pair & p2){
	return (p1.first == p2.first && p1.second == p2.second);
}

Occ_list & operator+= (Occ_list & dest, const Occ_list & src){
	for (auto i = src.begin(); i != src.end(); i++){
		dest[i->first] += i->second;
	}

	return dest;
}


Occ_list & operator-= (Occ_list & dest, const Occ_list & src){
	for (auto i = src.begin(); i != src.end(); i++){
		dest[i->first] -= i->second; //XXX Il faut supprimer l'entrée i->first si dest[i->first] == Pair (0, 0)
		if (dest[i->first] == Pair(0, 0)){
			dest.erase(i->first);
		}
	}

	return dest;
}

std::ostream & operator<< (std::ostream & os, const Pair & p){
	return os << "(" << p.first << ", " << p.second << ")";
}

std::ostream & operator<< (std::ostream & os, const Occ_list & ol){
	os << "Occ_list [\n";

	for (auto i = ol.begin(); i != ol.end(); i++){
		os << "\t" << i->first << " : " << i->second << "\n";
	}
	return os << "\n]\n";
}
