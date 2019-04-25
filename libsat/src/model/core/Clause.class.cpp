#include "libsat.hpp"

Clause::Clause () = default;

Clause::~Clause () = default;

Clause::Clause (const Clause & icl) {
	*this = icl;
}

Clause::Clause (const std::vector<int> & litts) {
	this->_litts.insert(litts.begin(), litts.end());
}

Clause & Clause::operator=(const Clause & icl) {
	if (this != &icl) {
		this->_litts    = icl.get_litts();
		this->satisfied = icl.is_satisfied();
	}
	return *this;
}

const std::set<int> & Clause::get_litts() const{
	return this->_litts;
}

const std::set<int> & Clause::get_absent_litts() const{
	return this->_absent_litts;
}

bool Clause::is_satisfied() const{
	return this->satisfied;
}

void Clause::remove_litt(int litt) {
	this->_litts.erase(litt);
	this->_absent_litts.insert(litt);
}

void Clause::add_litt(int litt) {
	this->_absent_litts.erase(litt);
	this->_litts.insert(litt);
}

void Clause::set_satisfied(bool b) {
	this->satisfied = b;
}

std::set<unsigned int> Clause::build_presence_set() const{
	std::set<unsigned int> res;

	for (int litt : this->_litts)
		res.insert(abs(litt));
	return (res);
}

int Clause::presence_litt(int litt) const{
	litt = abs(litt);

	if (this->_litts.find(litt) != this->_litts.end())
		return (1);

	if (this->_litts.find(-litt) != this->_litts.end())
		return (-1);

	return (0);
}

bool Clause::is_empty_clause() const{
	return (this->_litts.empty());
}

bool Clause::is_two_clause() const{
	return (this->_litts.size() == 2);
}

int Clause::is_unit_clause() const{
	if (this->_litts.size() != 1)
		return (0);

	return (*this->_litts.begin());
}

std::ostream & operator<<(std::ostream & os, const Clause & icl) {
	const std::set<int> & litts = icl.get_litts();
	std::set<unsigned int> pos_litts;
	std::set<unsigned int> neg_litts;

	for (int litt : litts) {
		if (litt > 0)
			pos_litts.insert(litt);
		else
			neg_litts.insert(-litt);
	}

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
