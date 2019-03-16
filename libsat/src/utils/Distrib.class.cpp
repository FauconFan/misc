#include "libsat.hpp"

Distrib::Distrib() {}
Distrib::~Distrib() {}

const std::unordered_map<unsigned int, bool> * Distrib::getDistrib() const {
	return &(this->_distrib);
}

void		Distrib::set(unsigned int k, bool v) {
	this->_distrib[k] = v;
}

std::ostream & operator<< (std::ostream & os, const Distrib & d){
	os << "Distrib [\n";

	for (auto it = d.getDistrib()->begin(); it != d.getDistrib()->end(); ++it) {
		os << "val " << it->first << " to " << it->second << "\n";
	}

	return os << "]\n";
}