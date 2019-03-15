#include "libsat.hpp"

Pair::Pair () : _left(0), _right(0) {}

Pair::Pair (const Pair & p) : _left(p._left), _right(p._right) {}

Pair::Pair (unsigned int l, unsigned int r) : _left(l), _right(r) {}

Pair::~Pair (){}

unsigned int Pair::getLeft () const {
	return this->_left;
}

unsigned int Pair::getRight () const {
	return this->_right;
}

Pair & Pair::operator+= (const Pair & p) {
	this->_left += p._left;
	this->_right += p._right;

	return *this;
}

Pair & Pair::operator-= (const Pair & p) {
	this->_left -= p._left;
	this->_right -= p._right;

	return *this;
}

bool Pair::operator== (const Pair & p) {
	return (this->_left == p._left && this->_right == p._right);
}

std::ostream & operator<< (std::ostream & os, const Pair & p) {
	return os << "(" << p.getLeft() << ", " << p.getRight() << ")";
}
