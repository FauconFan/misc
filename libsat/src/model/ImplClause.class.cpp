#include "libsat.hpp"

ImplClause::ImplClause () : _pos_litts(NULL), _neg_litts(NULL) {
	this->_pos_litts = new std::vector<unsigned int> ();
	this->_neg_litts = new std::vector<unsigned int> ();
}

ImplClause::ImplClause (const ImplClause & icl) : _pos_litts(NULL), _neg_litts(NULL) {
	*this = icl;
}

ImplClause::ImplClause (const Clause & cl) : ImplClause(*(cl.getLitts())) {}

ImplClause::ImplClause (const std::vector<int> litts) : _pos_litts(NULL), _neg_litts(NULL) {
	this->_pos_litts = new std::vector<unsigned int> ();
	this->_neg_litts = new std::vector<unsigned int> ();

	for (int current_elt : litts) {
		if (current_elt > 0)
			this->_pos_litts->push_back(current_elt);
		else
			this->_neg_litts->push_back(-current_elt);
	}
}

ImplClause & ImplClause::operator=(const ImplClause & icl) {
	if (this->_pos_litts != NULL)
		delete this->_pos_litts;
	if (this->_neg_litts != NULL)
		delete this->_neg_litts;

	this->_pos_litts = new std::vector<unsigned int>(*(icl.getPosLitts()));
	this->_neg_litts = new std::vector<unsigned int>(*(icl.getNegLitts()));

	return *this;
}

bool ImplClause::operator==(const ImplClause & rhs) const{
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

ImplClause::~ImplClause () {
	if (this->_pos_litts != NULL)
		delete this->_pos_litts;
	if (this->_neg_litts != NULL)
		delete this->_neg_litts;
}

std::vector<unsigned int> * ImplClause::getPosLitts() const{
	return this->_pos_litts;
}

std::vector<unsigned int> * ImplClause::getNegLitts() const{
	return this->_neg_litts;
}

ClauseType ImplClause::getType() const{
	return IMPLCLAUSE;
}

Occ_list ImplClause::get_occ_list() const{
	Occ_list res;

	for (unsigned int val : *(this->_pos_litts)) {
		// std::cout << "\nres.getContent()[val] before adding Pair (1, 0) : " << res.getContent()[val];
		res.addPair(val, Pair(1, 0));
		// res.getContent().at(val) += Pair (1, 0);
		// std::cout << "\nres.getContent()[val] after adding Pair (1, 0) :" << res.getContent()[val];
	}

	for (unsigned int val : *(this->_neg_litts)) {
		res.addPair(val, Pair(0, 1));
		// std::cout << "\nres.getContent()[val] before adding Pair (0, 1) :" << res.getContent()[val];
		// res.getContent()[val] += Pair (0, 1);
		// std::cout << "\nres.getContent()[val] after adding Pair (0, 1) :" << res.getContent()[val];
	}

	return res;
}

int ImplClause::contains_litt(int litt) const{
	if (litt < 0)
		litt = -litt;

	if (std::find(this->_neg_litts->begin(), this->_neg_litts->end(), litt) != this->_neg_litts->end())
		return -1;

	if (std::find(this->_pos_litts->begin(), this->_pos_litts->end(), litt) != this->_pos_litts->end())
		return 1;

	return 0;
}

bool ImplClause::is_tautology() const{
	for (unsigned int litt : *(this->_neg_litts)) {
		if (std::find(this->_pos_litts->begin(), this->_pos_litts->end(), litt) != this->_pos_litts->end()) {
			return true;
		}
	}

	return false;
}

Occ_list ImplClause::simplify_clause() {
	Occ_list res;
	std::set<unsigned int> buff;

	for (unsigned int val : *(this->_neg_litts)) {
		if (!buff.insert(val).second)
			res.addPair(val, Pair(0, 1));
		// res.getContent()[val] += Pair (0, 1);
	}

	this->_neg_litts->clear();
	this->_neg_litts->assign(buff.begin(), buff.end());
	buff.clear();

	for (unsigned int val : *(this->_pos_litts)) {
		if (!buff.insert(val).second)
			res.addPair(val, Pair(1, 0));
		// res.getContent()[val] += Pair (1, 0);
	}

	this->_pos_litts->clear();
	this->_pos_litts->assign(buff.begin(), buff.end());

	return res;
}

/*bool ImplClause::unit_propagation (Distrib & dist) const{
 *  int res = 0;
 *
 *  for (unsigned int val : *(this->_neg_litts)){
 *      auto current_elt = dist.find(val);
 *      if (current_elt == dist.end()){
 *          if (res != 0)
 *              return false;
 *          else
 *              res = -val;
 *      }else{
 *          if (current_elt->second == false)
 *              return false;
 *      }
 *  }
 *
 *  for (unsigned int val : *(this->_pos_litts)){
 *      auto current_elt = dist.find(val);
 *      if (current_elt == dist.end()){
 *          if (res != 0)
 *              return false;
 *          else
 *              res = val;
 *      }else{
 *          if (current_elt->second == true)
 *              return false;
 *      }
 *  }
 *
 *  if (res > 0)
 *      dist[res] = true;
 *  else if (res < 0)
 *      dist[-res] = false;
 *  else
 *      return false;
 *  return true;
 * }*/

ImplClause * cut(const ImplClause & icl1, const ImplClause & icl2, unsigned int val) {
	std::vector<unsigned int> * icl1_pos_litts;
	std::vector<unsigned int> * icl1_neg_litts;
	std::vector<unsigned int> * icl2_pos_litts;
	std::vector<unsigned int> * icl2_neg_litts;
	ImplClause * res_cut = new ImplClause();

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

	res_cut->getPosLitts()->assign(buff.begin(), buff.end());
	buff.clear();

	for (unsigned int i : *icl1_neg_litts) {
		if (i != val)
			buff.insert(i);
	}

	for (unsigned int i : *icl2_neg_litts) {
		if (i != val)
			buff.insert(i);
	}

	res_cut->getNegLitts()->assign(buff.begin(), buff.end());

	return res_cut;
} // cut

std::ostream & operator<<(std::ostream & os, const ImplClause & icl) {
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
