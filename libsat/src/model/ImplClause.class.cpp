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

ImplClause & ImplClause::operator= (const ImplClause & icl)
{
	if (this->_pos_litts != NULL)
		delete this->_pos_litts;
	if (this->_neg_litts != NULL)
		delete this->_neg_litts; 

	this->_pos_litts = new std::vector<unsigned int> (*(icl.getPosLitts()));
	this->_neg_litts = new std::vector<unsigned int> (*(icl.getNegLitts()));

	return *this;
}

bool ImplClause::operator==(const ImplClause & rhs) const {
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

ClauseType ImplClause::getType() const{
	return IMPLCLAUSE;
}

Occ_list ImplClause::get_occ_list () const{
	Occ_list res;

	for (unsigned int val : *(this->_pos_litts)){
		res[val] += Pair (1, 0);
	}

	for (unsigned int val : *(this->_neg_litts)){
		res[val] += Pair (0, 1);
	}

	return res;
}

void ImplClause::add (int val){
	if (val > 0){
		this->_pos_litts->push_back(val);
	}else{
		this->_neg_litts->push_back(-val);
	}
}

bool ImplClause::contains_litt (int litt) const
{
	if (litt < 0)
		return std::find(this->_neg_litts->begin(), this->_neg_litts->end(), -litt) != this->_neg_litts->end();
	return std::find(this->_pos_litts->begin(), this->_pos_litts->end(), litt) != this->_pos_litts->end();
}

bool ImplClause::is_tautology () const
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

Occ_list ImplClause::simplify_clause (){
	Occ_list res;
	std::set<unsigned int> buff;
	
	for (unsigned int val : *(this->_neg_litts)){
		if (!buff.insert(val).second)
			res[val] += Pair (0, 1);
	}

	this->_neg_litts->clear();
    this->_neg_litts->assign(buff.begin(), buff.end());
	buff.clear();

	for (unsigned int val : *(this->_pos_litts)){
		if (!buff.insert(val).second)
			res[val] += Pair (1, 0);
	}

	this->_pos_litts->clear();
    this->_pos_litts->assign(buff.begin(), buff.end());

	return res;
}

ImplClause * cut (const ImplClause & icl1, const ImplClause & icl2, unsigned int val){
	std::vector<unsigned int> * icl1_pos_litts;
   	std::vector<unsigned int> * icl1_neg_litts;
   	std::vector<unsigned int> *	icl2_pos_litts;
  	std::vector<unsigned int> * icl2_neg_litts;
	ImplClause * res_cut = new ImplClause();

	std::set<unsigned int> buff;

	icl1_pos_litts = icl1.getPosLitts();
	icl1_neg_litts = icl1.getNegLitts();
	icl2_pos_litts = icl2.getPosLitts();
	icl2_neg_litts = icl2.getNegLitts();

	for (unsigned int i : *icl1_pos_litts){
		if (i != val)
			buff.insert(i);
	}

	for (unsigned int i : *icl2_pos_litts){
		if (i != val)
			buff.insert(i);
	}

	res_cut->getPosLitts()->assign(buff.begin(), buff.end());
	buff.clear();

	for (unsigned int i : *icl1_neg_litts){
		if (i != val)
			buff.insert(i);
	}

	for (unsigned int i : *icl2_neg_litts){
		if (i != val)
			buff.insert(i);
	}

	res_cut->getNegLitts()->assign(buff.begin(), buff.end());

	return res_cut;
}

std::ostream & operator<<(std::ostream & os, const ImplClause & icl)
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
