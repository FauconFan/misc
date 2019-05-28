#include "sat.hpp"

Formula_builder::Formula_builder() = default;

Formula_builder::~Formula_builder() {
	if (this->_parent != nullptr) {
		this->_parent->_child = nullptr;
		delete this->_parent;
		this->_parent = nullptr;
	}
	if (this->_child != nullptr) {
		this->_child->_parent = nullptr;
		delete this->_child;
		this->_child = nullptr;
	}
}

Formula_builder * Formula_builder::frml_builder = nullptr;

void Formula_builder::init_formula() {
	if (Formula_builder::frml_builder != nullptr) {
		delete Formula_builder::frml_builder;
		Formula_builder::frml_builder = nullptr;
	}
	Formula_builder::frml_builder = new Formula_builder();
}

Formula Formula_builder::end_formula() {
	Formula frml = Formula_builder::frml_builder->_sub_formulas.front().gen_formula();

	delete Formula_builder::frml_builder;
	Formula_builder::frml_builder = nullptr;
	return (frml);
}

void Formula_builder::init_subformula_neg() {
	Formula_builder::frml_builder->_child = new Formula_builder();
	Formula_builder::frml_builder->_child->_parent = Formula_builder::frml_builder;
	Formula_builder::frml_builder = Formula_builder::frml_builder->_child;

	Formula_builder::frml_builder->_type = Neg;
}

void Formula_builder::init_subformula_binop(BinOp binop) {
	Formula_builder::frml_builder->_child = new Formula_builder();
	Formula_builder::frml_builder->_child->_parent = Formula_builder::frml_builder;
	Formula_builder::frml_builder = Formula_builder::frml_builder->_child;

	Formula_builder::frml_builder->_type = Bin;
	Formula_builder::frml_builder->binop = binop;
}

void Formula_builder::end_subformula() {
	Formula_builder::frml_builder = Formula_builder::frml_builder->_parent;

	Formula_builder::frml_builder->_child->_parent = nullptr;
	Formula_builder::frml_builder->_sub_formulas.push_back(*Formula_builder::frml_builder->_child);

	delete Formula_builder::frml_builder->_child;
	Formula_builder::frml_builder->_child = nullptr;
}

void Formula_builder::add_litt(int litt) {
	Formula_builder::frml_builder->_litts.push_back(litt);
}

Formula_builder::UnknownErrorException::UnknownErrorException(UnknownErrorType uet) : uet(uet) {}

const char * Formula_builder::UnknownErrorException::what() const throw() {
	switch (this->uet) {
		case SNH: {
			return ("Should never happened");
		}
		case UnknownType: {
			return ("Unknown Type error");
		}
	}
}

static Formula gen_balance_formula(BinOp binop, const std::vector<Formula> & vec) {
	std::vector<Formula> first;
	std::vector<Formula> last;

	if (vec.size() == 1)
		return (vec.front());

	auto middle = vec.begin() + vec.size() / 2;
	first.insert(first.begin(), vec.begin(), middle);
	last.insert(last.begin(), middle, vec.end());

	return (Formula::build_bin(binop, gen_balance_formula(binop, first), gen_balance_formula(binop, last)));
}

Formula Formula_builder::gen_formula(void) const{
	switch (this->_type) {
		case Neg: {
			if (this->_litts.empty() == true || this->_sub_formulas.size() != 1)
				throw Formula_builder::UnknownErrorException(SNH);
			return Formula::build_neg(this->_sub_formulas.front().gen_formula());
		}
		case Bin: {
			std::vector<Formula> vec_formulas;

			for (int litt : this->_litts)
				vec_formulas.push_back(Formula::build_litt(litt));

			for (const auto & frml_bd : this->_sub_formulas)
				vec_formulas.push_back(frml_bd.gen_formula());

			if (vec_formulas.empty()) {
				switch (this->binop) {
					case Or:
						return Formula::build_false();

					case And:
						return Formula::build_true();
				}
			}

			return (gen_balance_formula(this->binop, vec_formulas));
		}
		default: {
			throw Formula_builder::UnknownErrorException(UnknownType);
		}
	}
} // Formula_builder::gen_formula
