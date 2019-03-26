#include "libsat.hpp"

Clause::Clause () {
	this->_pos_litts = new std::vector<unsigned int> ();
	this->_neg_litts = new std::vector<unsigned int> ();
}

Clause::Clause (const Clause & icl) {
	*this = icl;
}

Clause::Clause (const std::vector<int> & litts) {
	this->_pos_litts = new std::vector<unsigned int> ();
	this->_neg_litts = new std::vector<unsigned int> ();

	for (int current_elt : litts) {
		if (current_elt > 0)
			this->_pos_litts->push_back(current_elt);
		else
			this->_neg_litts->push_back(-current_elt);
	}
}

Clause & Clause::operator=(const Clause & icl) {
	if (this != &icl) {
		if (this->_pos_litts != nullptr)
			delete this->_pos_litts;
		if (this->_neg_litts != nullptr)
			delete this->_neg_litts;

		this->_pos_litts = new std::vector<unsigned int>(*(icl.getPosLitts()));
		this->_neg_litts = new std::vector<unsigned int>(*(icl.getNegLitts()));
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

std::vector<unsigned int> * Clause::getPosLitts() const{
	return this->_pos_litts;
}

std::vector<unsigned int> * Clause::getNegLitts() const{
	return this->_neg_litts;
}

Occ_list Clause::get_occ_list() const{
	Occ_list res;

	for (unsigned int val : *(this->_pos_litts)) {
		res.addPair(val, Pair(1, 0));
	}

	for (unsigned int val : *(this->_neg_litts)) {
		res.addPair(val, Pair(0, 1));
	}

	return res;
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

Occ_list Clause::simplify_clause() {
	Occ_list res;
	std::set<unsigned int> buff;

	for (unsigned int val : *(this->_neg_litts)) {
		if (!buff.insert(val).second)
			res.addPair(val, Pair(0, 1));
	}

	this->_neg_litts->clear();
	this->_neg_litts->assign(buff.begin(), buff.end());
	buff.clear();

	for (unsigned int val : *(this->_pos_litts)) {
		if (!buff.insert(val).second)
			res.addPair(val, Pair(1, 0));
	}

	this->_pos_litts->clear();
	this->_pos_litts->assign(buff.begin(), buff.end());

	return res;
}

void Clause::assign_other_value(unsigned int val, Distrib & dist) const{
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

bool Clause::unit_propagation(Distrib & dist) const{
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

Clause cut(const Clause & icl1, const Clause & icl2, unsigned int val) {
	std::vector<unsigned int> * icl1_pos_litts;
	std::vector<unsigned int> * icl1_neg_litts;
	std::vector<unsigned int> * icl2_pos_litts;
	std::vector<unsigned int> * icl2_neg_litts;
	Clause res_cut;

	std::set<unsigned int> buff;

	icl1_pos_litts = icl1.getPosLitts();
	icl1_neg_litts = icl1.getNegLitts();
	icl2_pos_litts = icl2.getPosLitts();
	icl2_neg_litts = icl2.getNegLitts();

	for (unsigned int i : *icl1_pos_litts) {
		if (i != val)
			buff.insert(i);
	}

	for (unsigned int i : *icl2_pos_litts) {
		if (i != val)
			buff.insert(i);
	}

	res_cut.getPosLitts()->assign(buff.begin(), buff.end());
	buff.clear();

	for (unsigned int i : *icl1_neg_litts) {
		if (i != val)
			buff.insert(i);
	}

	for (unsigned int i : *icl2_neg_litts) {
		if (i != val)
			buff.insert(i);
	}

	res_cut.getNegLitts()->assign(buff.begin(), buff.end());

	return res_cut;
} // cut

std::ostream & operator<<(std::ostream & os, const Clause & icl) {
	std::vector<unsigned int> * pos_litts;
	std::vector<unsigned int> * neg_litts;
	unsigned int i, j;

	pos_litts = icl.getPosLitts();
	neg_litts = icl.getNegLitts();

	os << "Impl [";

	for (j = 0; j < neg_litts->size(); j++) {
		if (j != 0)
			os << " & ";
		os << neg_litts->at(j);
	}

	os << " -> ";

	for (i = 0; i < pos_litts->size(); i++) {
		if (i != 0)
			os << " | ";
		os << pos_litts->at(i);
	}

	return (os << "]\n");
}
