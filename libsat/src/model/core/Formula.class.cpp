#include "libsat.hpp"

Formula::Formula() = default;

Formula::~Formula() {
	switch (this->_type) {
		case None:
			delete this->_u.normal;
			break;
		case Neg:
			delete this->_u.neg;
			break;
		case Bin:
			delete this->_u.bin.left;
			delete this->_u.bin.right;
			break;
		default:
			break;
	}
}

Formula::Formula(const Formula & frml) {
	*this = frml;
}

Formula &Formula::operator=(const Formula & frml) {
	if (this != &frml) {
		this->_type = frml._type;
		switch (frml._type) {
			case Var:
				this->_u.litt = frml._u.litt;
				break;
			case None:
				this->_u.normal = new Formula(*frml._u.normal);
				break;
			case Neg:
				this->_u.neg = new Formula(*frml._u.neg);
				break;
			case Bin:
				this->_u.bin.binop = frml._u.bin.binop;
				this->_u.bin.left  = new Formula(*frml._u.bin.left);
				this->_u.bin.right = new Formula(*frml._u.bin.right);
				break;
			default:
				break;
		}
	}
	return (*this);
}

Formula Formula::build_litt(int litt) {
	Formula frml;

	frml._type   = Var;
	frml._u.litt = litt;
	return (frml);
}

Formula Formula::build_normal(const Formula & frml) {
	Formula frml_new;

	frml_new._type     = None;
	frml_new._u.normal = new Formula(frml);
	return (frml_new);
}

Formula Formula::build_neg(const Formula & frml_neg) {
	Formula frml;

	frml._type  = Neg;
	frml._u.neg = new Formula(frml_neg);
	return (frml);
}

Formula Formula::build_bin(BinOp binop, const Formula & frml1, const Formula & frml2) {
	Formula frml;

	frml._type        = Bin;
	frml._u.bin.binop = binop;
	frml._u.bin.left  = new Formula(frml1);
	frml._u.bin.right = new Formula(frml2);
	return (frml);
}

Formula Formula::build_true() {
	Formula frml;

	frml._type = True;
	return (frml);
}

Formula Formula::build_false() {
	Formula frml;

	frml._type = False;
	return (frml);
}

void Formula::display(std::ostream & os) const{
	switch (this->_type) {
		case Var:
			os << "Var {" << this->_u.litt << "}";
			break;
		case None:
			os << "None { ";
			this->_u.normal->display(os);
			os << " }";
			break;
		case True:
			os << "True";
			break;
		case False:
			os << "False";
			break;
		case Neg:
			os << "Neg { ";
			this->_u.neg->display(os);
			os << " }";
			break;
		case Bin:
			switch (this->_u.bin.binop) {
				case Or:
					os << "Or ";
					break;
				case And:
					os << "And ";
					break;
			}
			os << "{ ";
			this->_u.bin.left->display(os);
			os << ", ";
			this->_u.bin.right->display(os);
			os << " }";
	}
} // Formula::display

std::ostream &operator<<(std::ostream & os, const Formula & frml) {
	frml.display(os);
	os << std::endl;
	return (os);
}
