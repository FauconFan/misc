#include "libsat.hpp"

Occ_list::Occ_list () : _content() {}

Occ_list::Occ_list (const Occ_list & ol) : _content() {
	*this = ol;
}

Occ_list::Occ_list (const std::vector<ImplClause *> fnc){
	std::vector<unsigned int> pos_litts, neg_litts;

	for (auto i = fnc.begin(); i != fnc.end(); i++){
		pos_litts = *((*i)->getPosLitts());

		for (auto j = pos_litts.begin(); j != pos_litts.end(); j++){
			this->_content[*j] += Pair(1, 0);
		}

		neg_litts = *((*i)->getNegLitts());

		for (auto j = neg_litts.begin(); j < neg_litts.end(); j++){
			this->_content[*j] += Pair(0, 1);
		}
	}
}

Occ_list::~Occ_list (){}

Occ_list & Occ_list::operator+= (const Occ_list & ol){
	for (auto i = ol._content.begin(); i != ol._content.end(); i++){
		this->_content[i->first] += i->second;
	}

	return *this;
}


Occ_list & Occ_list::operator-= (const Occ_list & ol){
	for (auto i = ol._content.begin(); i != ol._content.end(); i++){
		this->_content[i->first] -= i->second;
		if (this->_content[i->first] == Pair(0, 0)){
			this->_content.erase(i->first);
		}
	}

	return *this;
}

const std::unordered_map<unsigned int, Pair> * Occ_list::getContent () const {
	return &(this->_content);
}

Pair Occ_list::getPair (unsigned int key) const {
	return this->_content.at(key);
}

void Occ_list::addPair (unsigned int key, const Pair p){
	this->_content[key] += p;
}

bool Occ_list::empty() const {
	return _content.empty();
}

std::ostream & operator<< (std::ostream & os, const Occ_list & ol){
	os << "Occ_list [\n";

	//auto content = ol.getContent();
	for (auto i = ol.getContent()->begin(); i != ol.getContent()->end(); i++){
	//for (auto i = ol.getContent().begin(); i != ol.getContent().end(); i++){
		os << "\t" << i->first << " : " << i->second << "\n";
	}

	return os << "]\n";
}

std::ostream & operator<< (std::ostream & os, const Distrib & d){
	os << "Distrib [\n";

	for (auto i : d) {
	//for (auto i = d.begin(); i != d.end(); i++){
		os << "val " << i.first << " to " << i.second << "\n";
	}

	return os << "]\n";
}
