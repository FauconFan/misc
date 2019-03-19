#include "libsat.hpp"

Distrib::Distrib() = default;

Distrib::~Distrib() = default;

const std::unordered_map<unsigned int, bool> * Distrib::getDistrib() const{
	return &(this->_distrib);
}

void Distrib::set(unsigned int k, bool v) {
	this->_distrib[k] = v;
}

std::ostream & operator<<(std::ostream & os, const Distrib & d) {
	os << "Distrib [\n";

	for (const auto & p : *d.getDistrib()) {
		os << "val " << p.first << " to " << p.second << "\n";
	}

	return os << "]\n";
}
