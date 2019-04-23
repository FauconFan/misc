#include "libsat.hpp"

Clause::Clause () = default;

Clause::~Clause () = default;

Clause::Clause (const Clause & icl) {
	*this = icl;
}

Clause::Clause (const std::vector<int> & litts) {
	for (int current_elt : litts) {
		if (current_elt > 0)
			this->_pos_litts.insert(current_elt);
		else
			this->_neg_litts.insert(-current_elt);
	}
}

Clause & Clause::operator=(const Clause & icl) {
	if (this != &icl) {
		this->_pos_litts = icl.get_pos_litts();
		this->_neg_litts = icl.get_neg_litts();
		this->satisfied  = icl.is_satisfied();
	}
	return *this;
}

const std::set<unsigned int> & Clause::get_pos_litts() const{
	return this->_pos_litts;
}

const std::set<unsigned int> & Clause::get_neg_litts() const{
	return this->_neg_litts;
}

bool Clause::is_satisfied() const{
	return this->satisfied;
}

void Clause::remove_litt(int litt) {
	if (litt > 0)
		this->_pos_litts.erase(litt);
	else
		this->_neg_litts.erase(-litt);
}

void Clause::add_litt(int litt) {
	if (litt > 0)
		this->_pos_litts.insert(litt);
	else
		this->_neg_litts.insert(-litt);
}

void Clause::set_satisfied(bool b) {
	this->satisfied = b;
}

std::set<unsigned int> Clause::build_presence_set() const{
	std::set<unsigned int> res;

	res.insert(this->_neg_litts.cbegin(), this->_neg_litts.cend());
	res.insert(this->_pos_litts.cbegin(), this->_pos_litts.cend());
	return (res);
}

Occ_list Clause::build_occ_list() const{
	Occ_list res;

	for (unsigned int val : (this->_pos_litts)) {
		res.add_pair(val, Pair(1, 0));
	}

	for (unsigned int val : (this->_neg_litts)) {
		res.add_pair(val, Pair(0, 1));
	}

	return res;
}

std::list<int> Clause::build_litts() const{
	std::list<int> res;

	for (unsigned int val : this->_pos_litts)
		res.push_back(val);
	for (unsigned int val : this->_neg_litts)
		res.push_back(-static_cast<int>(val));
	return (res);
}

int Clause::presence_litt(int litt) const{
	if (litt < 0)
		litt = -litt;

	if (std::find(this->_neg_litts.begin(), this->_neg_litts.end(), litt) != this->_neg_litts.end())
		return -1;

	if (std::find(this->_pos_litts.begin(), this->_pos_litts.end(), litt) != this->_pos_litts.end())
		return 1;

	return 0;
}

bool Clause::is_empty_clause() const{
	return (this->_neg_litts.empty() && this->_pos_litts.empty());
}

bool Clause::is_two_clause() const{
	return (this->_neg_litts.size() + this->_pos_litts.size() == 2);
}

int Clause::is_unit_clause() const{
	int res;

	res = 0;
	for (unsigned int val : this->_pos_litts) {
		if (res != 0)
			return 0;

		res = val;
	}

	for (unsigned int val : this->_neg_litts) {
		if (res != 0)
			return 0;

		res = -val;
	}

	return res;
}

std::ostream & operator<<(std::ostream & os, const Clause & icl) {
	const std::set<unsigned int> & pos_litts = icl.get_pos_litts();
	const std::set<unsigned int> & neg_litts = icl.get_neg_litts();

	os << "Impl [";

	for (auto j = neg_litts.cbegin(); j != neg_litts.cend(); j++) {
		if (j != neg_litts.cbegin())
			os << " & ";
		os << *j;
	}

	os << " -> ";

	for (auto i = pos_litts.cbegin(); i != pos_litts.cend(); i++) {
		if (i != pos_litts.cbegin())
			os << " | ";
		os << *i;
	}

	return (os << "]\n");
}
