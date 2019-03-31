#include "libsat.hpp"

Occ_list::Occ_list () = default;

Occ_list::Occ_list (const Occ_list & ol) = default;

Occ_list::Occ_list (const Fnc & fnc) {
	*this = fnc.build_occ_list();
}

Occ_list::~Occ_list () = default;

Occ_list & Occ_list::operator=(const Occ_list & ol) = default;

Occ_list & Occ_list::operator+=(const Occ_list & ol) {
	for (const auto & p : ol._content) {
		this->_content[p.first] += p.second;
	}
	return (*this);
}

Occ_list & Occ_list::operator-=(const Occ_list & ol) {
	for (const auto & p : ol._content) {
		this->_content[p.first] -= p.second;
		if (this->_content[p.first] == Pair(0, 0)) {
			this->_content.erase(p.first);
		}
	}

	return *this;
}

bool Occ_list::operator==(const Occ_list & ol) const{
	return this->_content == ol._content;
}

Pair Occ_list::getPair(unsigned int key) const{
	return this->_content.at(key);
}

void Occ_list::addPair(unsigned int key, const Pair & p) {
	this->_content[key] += p;
}

bool Occ_list::empty() const{
	return _content.empty();
}

unsigned int Occ_list::getMinOccu() const{
	unsigned int res;
	unsigned int nb;

	res = 0;
	nb  = -1; // Max value
	if (this->_content.empty())
		return (0);

	for (auto i : this->_content) {
		unsigned int current;

		current = i.second.getLeft() + i.second.getRight();
		if (current < nb) {
			nb  = current;
			res = i.first;
		}
	}
	return (res);
}

unsigned int Occ_list::getMaxOccu() const{
	unsigned int res;
	unsigned int nb;

	res = 0;
	nb  = 0; // Min value
	if (this->_content.empty())
		return (0);

	for (auto i : this->_content) {
		unsigned int current;

		current = i.second.getLeft() + i.second.getRight();
		if (current > nb) {
			nb  = current;
			res = i.first;
		}
	}
	return (res);
}

std::pair<std::vector<unsigned int>, std::vector<unsigned int> > Occ_list::getSoloPolarity() const{
	std::vector<unsigned int> pos;
	std::vector<unsigned int> neg;

	for (auto i : this->_content) {
		if (i.second.getLeft() == 0)
			neg.push_back(i.first);
		else if (i.second.getRight() == 0)
			pos.push_back(i.first);
	}
	return (std::make_pair(pos, neg));
}

void Occ_list::display(std::ostream & os) const{
	os << "Occ_list [\n";

	for (auto i : this->_content) {
		os << "\t" << i.first << " : " << i.second << "\n";
	}

	os << "]\n";
}

std::ostream & operator<<(std::ostream & os, const Occ_list & ol) {
	ol.display(os);
	return os;
}
