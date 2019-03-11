#include "libsat.hpp"

ImplClause::ImplClause () : _pos_litts(NULL), _neg_litts(NULL)
{
	this->_pos_litts = new std::vector<unsigned int> ();
	this->_neg_litts = new std::vector<unsigned int> ();
}

ImplClause::ImplClause (const ImplClause & icl) : _pos_litts(NULL), _neg_litts(NULL)
{
	*this = icl;
}

ImplClause::ImplClause (const Clause & cl) : ImplClause(*(cl.getLitts())) {}

ImplClause::ImplClause (const std::vector<int> litts) : _pos_litts(NULL), _neg_litts(NULL)
{
	unsigned int i;
	int current_elt;

	this->_pos_litts = new std::vector<unsigned int> ();
	this->_neg_litts = new std::vector<unsigned int> ();

	for (i = 0; i < litts.size(); i++){
		current_elt = litts.at(i);
		if (current_elt > 0)
			this->_pos_litts->push_back(current_elt);
		else
			this->_neg_litts->push_back(-current_elt);
	}
}

ImplClause &ImplClause::operator= (const ImplClause & icl)
{
	if (this->_pos_litts != NULL)
		delete this->_pos_litts;
	if (this->_neg_litts != NULL)
		delete this->_neg_litts; 

	this->_pos_litts = new std::vector<unsigned int> (*(icl.getPosLitts()));
	this->_neg_litts = new std::vector<unsigned int> (*(icl.getNegLitts()));

	return *this;
}

ImplClause::~ImplClause ()
{
	if (this->_pos_litts != NULL)
		delete this->_pos_litts;
	if (this->_neg_litts != NULL)
		delete this->_neg_litts;
}

std::vector<unsigned int> * ImplClause::getPosLitts () const
{
	return this->_pos_litts;
}

std::vector<unsigned int> * ImplClause::getNegLitts () const
{
	return this->_neg_litts;
}

bool ImplClause::contains_litt (int litt)
{
	if (litt < 0)
		return std::find(this->_neg_litts->begin(), this->_neg_litts->end(), litt) != this->_neg_litts->end();
	return std::find(this->_pos_litts->begin(), this->_pos_litts->end(), litt) != this->_pos_litts->end();
}

bool ImplClause::equals (const ImplClause & icl)
{
	if (this->_pos_litts->size() != icl._pos_litts->size() || this->_neg_litts->size() != icl._neg_litts->size())
		return false;

	for (auto i = this->_pos_litts->begin(); i != this->_pos_litts->end(); i++){
		if (std::find(icl._pos_litts->begin(), icl._pos_litts->end(), *i) == icl._pos_litts->end())
			return false;
	}

	for (auto i = this->_neg_litts->begin(); i != this->_neg_litts->end(); i++){
		if (std::find(icl._neg_litts->begin(), icl._neg_litts->end(), *i) == icl._neg_litts->end())
			return false;
	}

	return true;
}

bool ImplClause::isTautology ()
{
	unsigned i, j;

	for (i = 0; i < this->_neg_litts->size(); i++){
		for (j = 0; j < this->_pos_litts->size(); j++){
			if (this->_neg_litts->at(i) == this->_pos_litts->at(j))
				return true;
		}
	}

	return false;
}

void ImplClause::simplify_clause (occ_list & ol){
	unsigned int i,j;

	for (i = 0; i < this->_neg_litts->size(); i++){
		for (j = i + 1; j < this->_neg_litts->size(); j++){
			if (_neg_litts->at(i) == _neg_litts->at(j)){
				_neg_litts->erase(_neg_litts->begin() + j);
				ol[_neg_litts->at(i)]=ol[_neg_litts->at(i)] + pair(0, -1);
				j--;
			}
		}
	}

	for (i = 0; i < this->_pos_litts->size(); i++){
		for (j = i + 1; j < this->_pos_litts->size(); j++){
			if (_pos_litts->at(i) == _pos_litts->at(j)){
				_pos_litts->erase(_pos_litts->begin() + j);
				ol[_pos_litts->at(i)]=ol[_pos_litts->at(i)] + pair(-1, 0);
				j--;
			}
		}
	}
}

ImplClause cut (ImplClause & dest_icl, const ImplClause & src_icl){
	const std::vector<unsigned int> * src_pos_litts;
	const std::vector<unsigned int> * src_neg_litts;
	std::vector<unsigned int> * dest_pos_litts;
	std::vector<unsigned int> * dest_neg_litts;

	src_pos_litts = src_icl.getPosLitts();
	src_neg_litts = src_icl.getNegLitts();
	dest_pos_litts = dest_icl.getPosLitts();
	dest_neg_litts = dest_icl.getNegLitts();

	for (auto i = src_pos_litts->begin(); i != src_pos_litts->end(); i++){
		if (std::find(dest_pos_litts->begin(), dest_pos_litts->end(), *i) == dest_pos_litts->end())
			dest_pos_litts->push_back(*i);
	}

	for (auto i = src_neg_litts->begin(); i != src_neg_litts->end(); i++){
		if (std::find(dest_neg_litts->begin(), dest_neg_litts->end(), *i) == dest_neg_litts->end())
			dest_neg_litts->push_back(*i);
	}

	return dest_icl;
}

std::ostream &operator<<(std::ostream & os, const ImplClause & icl)
{
	std::vector<unsigned int> * pos_litts;
	std::vector<unsigned int> *	neg_litts;
	unsigned int i, j;

	pos_litts = icl.getPosLitts();
	neg_litts = icl.getNegLitts();

	os << "Impl [";

	for (j = 0; j < neg_litts->size(); j++){
		if (j != 0)
			os << " & ";
		os << neg_litts->at(j);
	}

	os << " -> ";

	for (i = 0; i < pos_litts->size(); i++){
		if (i != 0)
			os << " | ";
		os << pos_litts->at(i);
	}

	return (os << "]\n");
}
