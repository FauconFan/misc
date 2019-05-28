#ifndef FORMULA_CLASS_HPP
#define	FORMULA_CLASS_HPP

#include "libsat.hpp"

enum TypeFormula{
	Var,
	None,
	True,
	False,
	Neg,
	Bin,
};

enum BinOp{
	Or,
	And,
};

class Formula{
	public:
		virtual~Formula();

		Formula(const Formula & frml);
		Formula &operator=(const Formula & frml);

		static Formula build_litt(int litt);
		static Formula build_normal(const Formula & frml);
		static Formula build_neg(const Formula & frml_neg);
		static Formula build_bin(BinOp binop, const Formula & frml1, const Formula & frml2);
		static Formula build_true();
		static Formula build_false();

		void display(std::ostream &) const;

	private:
		TypeFormula _type {None};
		union {
			int       litt {0};
			Formula * normal;
			Formula * neg;
			struct {
				BinOp     binop;
				Formula * left;
				Formula * right;
			} bin;
		} _u;

		Formula(); // internal use only
};

std::ostream &operator<<(std::ostream &, const Formula & frml);

#endif // ifndef FORMULA_CLASS_HPP
