#include "libsat.hpp"

Occ_list::Occ_list ()  = default;
Occ_list::~Occ_list () = default;

Occ_list::Occ_list (const Occ_list & ol) = default;

Occ_list & Occ_list::operator=(const Occ_list & ol) = default;

const IPair Occ_list::get_count(unsigned int key) const{
	const auto & pset = this->_content.at(key);

	return IPair(pset.first.size(), pset.second.size());
}

const std::set<unsigned int> &Occ_list::get_pos_occu(unsigned int key) const{
	return (this->_content.at(key).first);
}

const std::set<unsigned int> &Occ_list::get_neg_occu(unsigned int key) const{
	return (this->_content.at(key).second);
}

std::pair<std::vector<unsigned int>, std::vector<unsigned int> > Occ_list::build_solo_polarity() const{
	std::vector<unsigned int> pos;
	std::vector<unsigned int> neg;

	for (const auto & pset : this->_content) {
		if (pset.second.first.empty())
			neg.push_back(pset.first);
		else if (pset.second.second.empty())
			pos.push_back(pset.first);
	}
	return (std::make_pair(pos, neg));
}

std::set<unsigned int> Occ_list::build_present_variables() const{
	std::set<unsigned int> res;

	for (const auto & p : this->_content) {
		res.insert(p.first);
	}
	return (res);
}

void Occ_list::set_content(const std::vector<Clause> & clauses) {
	unsigned int clause_id = 0;

	this->_content.clear();
	for (const auto & cl : clauses) {
		this->add_clause_id(cl.get_litts(), clause_id);
		clause_id++;
	}
}

void Occ_list::add_clause_id(unsigned int litt_id, unsigned int clause_id, bool side) {
	if (side)
		this->_content[litt_id].first.insert(clause_id);
	else
		this->_content[litt_id].second.insert(clause_id);
}

void Occ_list::add_clause_id(const std::set<int> & sint, unsigned int clause_id) {
	for (int val : sint) {
		if (val > 0)
			this->_content[val].first.insert(clause_id);
		else
			this->_content[-val].second.insert(clause_id);
	}
}

void Occ_list::remove_clause_id(unsigned int litt_id, unsigned int clause_id, bool side) {
	auto & pset = this->_content[litt_id];

	if (side)
		pset.first.erase(clause_id);
	else
		pset.second.erase(clause_id);
	if (pset.first.empty() && pset.second.empty())
		this->_content.erase(litt_id);
}

void Occ_list::remove_clause_id(const std::set<int> & sint, unsigned int clause_id) {
	for (int val : sint) {
		this->remove_clause_id(abs(val), clause_id, val > 0);
	}
}

bool Occ_list::empty() const{
	return _content.empty();
}

unsigned int Occ_list::stat_min_occu() const{
	unsigned int res;
	unsigned int nb;

	res = 0;
	nb  = -1; // Max value
	if (this->_content.empty())
		return (0);

	for (const auto & pset : this->_content) {
		unsigned int current;

		current = pset.second.first.size() + pset.second.second.size();
		if (current < nb) {
			nb  = current;
			res = pset.first;
		}
	}
	return (res);
}

unsigned int Occ_list::stat_max_occu() const{
	unsigned int res;
	unsigned int nb;

	res = 0;
	nb  = 0; // Min value
	if (this->_content.empty())
		return (0);

	for (const auto & pset : this->_content) {
		unsigned int current;

		current = pset.second.first.size() + pset.second.second.size();
		if (current > nb) {
			nb  = current;
			res = pset.first;
		}
	}
	return (res);
}

void Occ_list::display(std::ostream & os) const{
	os << "Occ_list [\n";

	for (const auto & pset : this->_content) {
		os << "\t" << pset.first << " : \npos\t";
		for (unsigned int clause_id_pos : pset.second.first) {
			os << clause_id_pos << " ";
		}
		os << "\nneg\t";
		for (unsigned int clause_id_neg : pset.second.second) {
			os << clause_id_neg << " ";
		}
		os << "\n";
	}

	os << "]\n";
}

std::ostream & operator<<(std::ostream & os, const Occ_list & ol) {
	ol.display(os);
	return os;
}
