#include "libsat.hpp"

IPair::IPair () = default;

IPair::IPair (const IPair & p) = default;

IPair::IPair (unsigned int l, unsigned int r) : _left(l), _right(r) {}

IPair::~IPair () = default;

IPair    &IPair::operator=(IPair const & rhs) {
	this->_left  = rhs.get_left();
	this->_right = rhs.get_right();
	return (*this);
}

unsigned int IPair::get_left() const{
	return this->_left;
}

unsigned int IPair::get_right() const{
	return this->_right;
}

bool IPair::operator==(const IPair & p) const{
	return (this->_left == p._left && this->_right == p._right);
}

std::ostream & operator<<(std::ostream & os, const IPair & p) {
	return os << "(" << p.get_left() << ", " << p.get_right() << ")";
}
