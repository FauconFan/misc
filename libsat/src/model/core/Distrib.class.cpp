#include "libsat.hpp"

Distrib::Distrib()  = default;
Distrib::~Distrib() = default;

Distrib::Distrib(const Occ_list & occ_list)
	: _present_variables(occ_list.buildPresentVariables())
{}

Distrib::Distrib(const Distrib & dist) = default;

Distrib &Distrib::operator=(const Distrib & dist) = default;

const std::unordered_map<unsigned int, bool> * Distrib::getDistrib() const{
	return &(this->_distrib);
}

bool Distrib::get(unsigned int k) const{
	return this->_distrib.at(k);
}

void Distrib::set(unsigned int k, bool v) {
	this->_distrib[k] = v;
}

std::unordered_map<unsigned int, bool, std::hash<unsigned int>, std::equal_to<>,
  std::allocator<std::pair<const unsigned int, bool> > >::const_iterator Distrib::find(unsigned int k) const{
	return this->_distrib.find(k);
}

std::unordered_map<unsigned int, bool, std::hash<unsigned int>, std::equal_to<>,
  std::allocator<std::pair<const unsigned int, bool> > >::const_iterator Distrib::end() const{
	return this->_distrib.end();
}

void Distrib::finish() {
	for (const auto & ui : this->_present_variables) {
		if (this->_distrib.find(ui) == this->_distrib.end()) {
			this->_distrib[ui] = false;
		}
	}
}

std::ostream & operator<<(std::ostream & os, const Distrib & d) {
	os << "Distrib [\n";

	for (const auto & p : *d.getDistrib()) {
		os << "val " << p.first << " to " << p.second << "\n";
	}

	return os << "]\n";
}
