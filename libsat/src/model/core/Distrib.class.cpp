#include "libsat.hpp"

Distrib::Distrib()  = default;
Distrib::~Distrib() = default;

Distrib::Distrib(const Distrib & dist) = default;
Distrib &Distrib::operator=(const Distrib & dist) = default;

const std::unordered_map<unsigned int, bool> & Distrib::get_distrib() const{
	return (this->_distrib);
}

void Distrib::set_presence_variables(const std::vector<Clause> & clauses) {
	std::set<unsigned int> s;

	for (const auto & cl : clauses) {
		const auto & pre_s = cl.build_presence_set();
		s.insert(pre_s.cbegin(), pre_s.cend());
	}
	this->_present_variables = s;
}

bool Distrib::get(unsigned int id) const{
	return this->_distrib.at(id);
}

void Distrib::set(unsigned int id, bool b) {
	this->_distrib[id] = b;
}

void Distrib::remove(unsigned int id) {
	this->_distrib.erase(id);
}

void Distrib::finalize() {
	for (unsigned int var : this->_present_variables) {
		if (this->_distrib.find(var) == this->_distrib.end()) {
			Logger::info() << "variable not set : " << var << " -> false\n";
			this->_distrib[var] = false;
		}
	}
}

std::ostream & operator<<(std::ostream & os, const Distrib & d) {
	os << "Distrib [\n";

	for (const auto & p : d.get_distrib()) {
		os << "val " << p.first << " to " << p.second << "\n";
	}

	return os << "]\n";
}
