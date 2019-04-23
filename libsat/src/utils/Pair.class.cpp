#include "libsat.hpp"

Pair::Pair () = default;

Pair::Pair (const Pair & p) = default;

Pair::Pair (unsigned int l, unsigned int r) : _left(l), _right(r) {}

Pair::~Pair () = default;

Pair    &Pair::operator=(Pair const & rhs) {
	this->_left  = rhs.get_left();
	this->_right = rhs.get_right();
	return (*this);
}

unsigned int Pair::get_left() const{
	return this->_left;
}

unsigned int Pair::get_right() const{
	return this->_right;
}

Pair & Pair::operator+=(const Pair & p) {
	this->_left  += p._left;
	this->_right += p._right;

	return *this;
}

Pair & Pair::operator-=(const Pair & p) {
	this->_left  -= p._left;
	this->_right -= p._right;

	return *this;
}

bool Pair::operator==(const Pair & p) const{
	return (this->_left == p._left && this->_right == p._right);
}

std::ostream & operator<<(std::ostream & os, const Pair & p) {
	return os << "(" << p.get_left() << ", " << p.get_right() << ")";
}
