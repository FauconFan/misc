#include "libsat.hpp"

Clause::Clause () {
	this->_pos_litts = new std::set<unsigned int> ();
	this->_neg_litts = new std::set<unsigned int> ();
}

Clause::Clause (const Clause & icl) {
	*this = icl;
}

Clause::Clause (const std::vector<int> & litts) {
	this->_pos_litts = new std::set<unsigned int> ();
	this->_neg_litts = new std::set<unsigned int> ();

	for (int current_elt : litts) {
		if (current_elt > 0)
			this->_pos_litts->insert(current_elt);
		else
			this->_neg_litts->insert(-current_elt);
	}
}

Clause & Clause::operator=(const Clause & icl) {
	if (this != &icl) {
		if (this->_pos_litts != nullptr)
			delete this->_pos_litts;
		if (this->_neg_litts != nullptr)
			delete this->_neg_litts;

		this->_pos_litts = new std::set<unsigned int>(*(icl.getPosLitts()));
		this->_neg_litts = new std::set<unsigned int>(*(icl.getNegLitts()));
	}
	return *this;
}

bool Clause::operator==(const Clause & rhs) const{
	for (unsigned int val : *(this->_neg_litts)) {
		if (std::find(rhs.getNegLitts()->begin(), rhs.getNegLitts()->end(), val) == rhs.getNegLitts()->end())
			return (false);
	}

	for (unsigned int val : *(this->_pos_litts)) {
		if (std::find(rhs.getPosLitts()->begin(), rhs.getPosLitts()->end(), val) == rhs.getPosLitts()->end())
			return (false);
	}

	return (true);
}

Clause::~Clause () {
	if (this->_pos_litts != nullptr)
		delete this->_pos_litts;
	if (this->_neg_litts != nullptr)
		delete this->_neg_litts;
}

std::set<unsigned int> * Clause::getPosLitts() const{
	return this->_pos_litts;
}

std::set<unsigned int> * Clause::getNegLitts() const{
	return this->_neg_litts;
}

std::list<int>           Clause::buildLitts() const{
	std::list<int> res;

	for (unsigned int neg : *this->_neg_litts) {
		res.push_back(static_cast<int>(neg) * -1);
	}
	for (unsigned int pos : *this->_pos_litts) {
		res.push_back(static_cast<int>(pos));
	}
	return (res);
}

Occ_list Clause::build_occ_list() const{
	Occ_list res;

	for (unsigned int val : *(this->_pos_litts)) {
		res.addPair(val, Pair(1, 0));
	}

	for (unsigned int val : *(this->_neg_litts)) {
		res.addPair(val, Pair(0, 1));
	}

	return res;
}

void Clause::remove_litt(int litt) {
	if (litt > 0)
		this->_pos_litts->erase(litt);
	else
		this->_neg_litts->erase(-litt);
}

int Clause::contains_litt(int litt) const{
	if (litt < 0)
		litt = -litt;

	if (std::find(this->_neg_litts->begin(), this->_neg_litts->end(), litt) != this->_neg_litts->end())
		return -1;

	if (std::find(this->_pos_litts->begin(), this->_pos_litts->end(), litt) != this->_pos_litts->end())
		return 1;

	return 0;
}

bool Clause::is_tautology() const{
	for (unsigned int litt : *(this->_neg_litts)) {
		if (std::find(this->_pos_litts->begin(), this->_pos_litts->end(), litt) != this->_pos_litts->end()) {
			return true;
		}
	}

	return false;
}

bool Clause::is_empty_clause() const{
	return (this->_neg_litts->empty() && this->_pos_litts->empty());
}

bool Clause::is_two_clause() const{
	return (this->_neg_litts->size() + this->_pos_litts->size() == 2);
}

int Clause::is_unit_clause() const{
	int res;

	res = 0;
	for (unsigned int val : *this->_pos_litts) {
		if (res != 0)
			return 0;

		res = val;
	}

	for (unsigned int val : *this->_neg_litts) {
		if (res != 0)
			return 0;

		res = -val;
	}

	return res;
}

void Clause::cut_assign_other_value(unsigned int val, Distrib & dist) const{
	for (unsigned int i : *(this->_neg_litts)) {
		if (i == val)
			continue;
		if (dist.find(i) == dist.end()) {
			dist.set(i, true);
		}
	}

	for (unsigned int i : *(this->_pos_litts)) {
		if (i == val)
			continue;
		if (dist.find(i) == dist.end()) {
			dist.set(i, false);
		}
	}
}

bool Clause::deduce_unit_propagation(Distrib & dist) const{
	int res = 0;

	for (unsigned int val : *(this->_neg_litts)) {
		auto current_elt = dist.find(val);
		if (current_elt == dist.end()) {
			if (res != 0)
				return false;

			res = -val;
		}
		else {
			if (current_elt->second == false)
				return false;
		}
	}

	for (unsigned int val : *(this->_pos_litts)) {
		auto current_elt = dist.find(val);
		if (current_elt == dist.end()) {
			if (res != 0)
				return false;

			res = val;
		}
		else {
			if (current_elt->second == true)
				return false;
		}
	}

	if (res > 0)
		dist.set(res, true);
	else if (res < 0)
		dist.set(-res, false);
	else
		return false;

	return true;
} // Clause::unit_propagation

std::ostream & operator<<(std::ostream & os, const Clause & icl) {
	std::set<unsigned int> * pos_litts;
	std::set<unsigned int> * neg_litts;

	pos_litts = icl.getPosLitts();
	neg_litts = icl.getNegLitts();

	os << "Impl [";

	for (auto j = neg_litts->cbegin(); j != neg_litts->cend(); j++) {
		if (j != neg_litts->cbegin())
			os << " & ";
		os << *j;
	}

	os << " -> ";

	for (auto i = pos_litts->cbegin(); i != pos_litts->cend(); i++) {
		if (i != pos_litts->cbegin())
			os << " | ";
		os << *i;
	}

	return (os << "]\n");
}
