#include "libsat.hpp"

Occ_list::Occ_list () : _content() {}

Occ_list::Occ_list (const Occ_list & ol) : _content() {
	*this = ol;
}

Occ_list::Occ_list (const std::vector<ImplClause *> fnc) {
	std::vector<unsigned int> pos_litts, neg_litts;

	for (auto i = fnc.begin(); i != fnc.end(); i++) {
		pos_litts = *((*i)->getPosLitts());

		for (auto j = pos_litts.begin(); j != pos_litts.end(); j++) {
			this->_content[*j] += Pair(1, 0);
		}

		neg_litts = *((*i)->getNegLitts());

		for (auto j = neg_litts.begin(); j < neg_litts.end(); j++) {
			this->_content[*j] += Pair(0, 1);
		}
	}
}

Occ_list::~Occ_list () {}

Occ_list & Occ_list::operator=(const Occ_list & ol) {
	this->_content = ol._content;
	return (*this);
}

Occ_list & Occ_list::operator+=(const Occ_list & ol) {
	for (auto i = ol._content.begin(); i != ol._content.end(); i++) {
		this->_content[i->first] += i->second;
	}

	return *this;
}

Occ_list & Occ_list::operator-=(const Occ_list & ol) {
	for (auto i = ol._content.begin(); i != ol._content.end(); i++) {
		this->_content[i->first] -= i->second;
		if (this->_content[i->first] == Pair(0, 0)) {
			this->_content.erase(i->first);
		}
	}

	return *this;
}

Pair Occ_list::getPair(unsigned int key) const{
	return this->_content.at(key);
}

void Occ_list::addPair(unsigned int key, const Pair p) {
	this->_content[key] += p;
}

bool Occ_list::empty() const{
	return _content.empty();
}

unsigned int Occ_list::getMinOccu() const{
	unsigned int res;
	unsigned int nb;
	unsigned int current;

	res = 0;
	nb  = -1; // Max value
	if (this->_content.empty())
		return (0);

	for (auto i : this->_content) {
		current = i.second.getLeft() + i.second.getRight();
		if (current < nb) {
			current = nb;
			res     = i.first;
		}
	}
	return (res);
}

unsigned int Occ_list::getMaxOccu() const{
	unsigned int res;
	unsigned int nb;
	unsigned int current;

	res = 0;
	nb  = 0; // Min value
	if (this->_content.empty())
		return (0);

	for (auto i : this->_content) {
		current = i.second.getLeft() + i.second.getRight();
		if (current > nb) {
			current = nb;
			res     = i.first;
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
