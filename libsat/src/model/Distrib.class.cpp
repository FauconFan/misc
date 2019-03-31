#include "libsat.hpp"

Distrib::Distrib()  = default;
Distrib::~Distrib() = default;

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

/*bool Distrib::contains(unsigned int val) const {
 *  return (this->_distrib.end() != this->_distrib.find(val));
 * }*/

std::ostream & operator<<(std::ostream & os, const Distrib & d) {
	os << "Distrib [\n";

	for (const auto & p : *d.getDistrib()) {
		os << "val " << p.first << " to " << p.second << "\n";
	}

	return os << "]\n";
}
