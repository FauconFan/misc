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
			this->_neg_litts->push_back(current_elt);
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

void ImplClause::simplify (){
	unsigned int i,j;

	for (i = 0; i < this->_neg_litts->size(); i++){
		for (j = i + 1; j < this->_neg_litts->size(); j++){
			if (_neg_litts->at(i) == _neg_litts->at(j)){
				_neg_litts->erase(_neg_litts->begin() + j);
				j--;
			}
		}
	}

	for (i = 0; i < this->_pos_litts->size(); i++){
		for (j = i + 1; j < this->_pos_litts->size(); j++){
			if (_pos_litts->at(i) == _pos_litts->at(j)){
				_pos_litts->erase(_pos_litts->begin() + j);
				j--;
			}
		}
	}
}

std::ostream &operator<<(std::ostream & os, const ImplClause & icl)
{
	std::vector<unsigned int> * pos_litts;
	std::vector<unsigned int> * neg_litts;
	unsigned int i, j;

	pos_litts = icl.getPosLitts();
	neg_litts = icl.getNegLitts();

	os << "Impl [";

	for (j = 0; j < neg_litts->size(); j++){
		if (j != 0)
			os << " & ";
		os << -neg_litts->at(j);
	}

	os << " -> ";

	for (i = 0; i < pos_litts->size(); i++){
		if (i != 0)
			os << " | ";
		os << pos_litts->at(i);
	}

	return (os << "]\n");
}
