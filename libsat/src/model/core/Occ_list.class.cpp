#include "libsat.hpp"

Occ_list::Occ_list ()  = default;
Occ_list::~Occ_list () = default;

Occ_list::Occ_list (const Occ_list & ol) = default;

Occ_list & Occ_list::operator=(const Occ_list & ol) = default;

Pair Occ_list::get_pair(unsigned int key) const{
	return this->_content.at(key);
}

void Occ_list::add_pair(unsigned int key, const Pair & p) {
	this->_content[key] += p;
}

void Occ_list::sub_pair(unsigned int key, const Pair & p) {
	this->_content[key] -= p;
	if (this->_content[key] == Pair(0, 0))
		this->_content.erase(key);
}

void Occ_list::set_content(const std::vector<Clause> & clauses) {
	this->_content = std::unordered_map<unsigned int, Pair>();

	for (const auto & cl : clauses) {
		*this += cl.build_occ_list();
	}
}

std::pair<std::vector<unsigned int>, std::vector<unsigned int> > Occ_list::build_solo_polarity() const{
	std::vector<unsigned int> pos;
	std::vector<unsigned int> neg;

	for (auto i : this->_content) {
		if (i.second.get_left() == 0)
			neg.push_back(i.first);
		else if (i.second.get_right() == 0)
			pos.push_back(i.first);
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

Occ_list & Occ_list::operator+=(const Occ_list & ol) {
	for (const auto & p : ol._content) {
		this->_content[p.first] += p.second;
	}
	return (*this);
}

Occ_list & Occ_list::operator-=(const Occ_list & ol) {
	for (const auto & p : ol._content) {
		this->_content[p.first] -= p.second;
		if (this->_content[p.first] == Pair(0, 0)) {
			this->_content.erase(p.first);
		}
	}

	return *this;
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

	for (auto i : this->_content) {
		unsigned int current;

		current = i.second.get_left() + i.second.get_right();
		if (current < nb) {
			nb  = current;
			res = i.first;
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

	for (auto i : this->_content) {
		unsigned int current;

		current = i.second.get_left() + i.second.get_right();
		if (current > nb) {
			nb  = current;
			res = i.first;
		}
	}
	return (res);
}

void Occ_list::display(std::ostream & os) const{
	os << "Occ_list [\n";

	for (auto i : this->_content) {
		os << "\t" << i.first << " : " << i.second << "\n";
	}

	os << "]\n";
}

std::ostream & operator<<(std::ostream & os, const Occ_list & ol) {
	ol.display(os);
	return os;
}
