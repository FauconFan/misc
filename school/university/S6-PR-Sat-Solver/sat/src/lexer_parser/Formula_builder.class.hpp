#ifndef FORMULA_BUILDER_CLASS_HPP
#define	FORMULA_BUILDER_CLASS_HPP

#include "sat.hpp"

enum UnknownErrorType{
	NegFormat,
	UnknownType,
};

class Formula_builder final{
	public:
		virtual~Formula_builder();

		static void init_formula();
		static Formula end_formula();

		static void init_subformula_neg();
		static void init_subformula_binop(BinOp binop);
		static void end_subformula();
		static void add_litt(int litt);

	private:
		std::list<int> _litts {};
		std::list<Formula_builder> _sub_formulas {};
		Formula_builder * _parent {nullptr};
		Formula_builder * _child {nullptr};
		TypeFormula _type {None};
		BinOp binop {Or}; // default value, do not trust, except if type is Bin

		Formula_builder(); // default parent

		static Formula_builder * frml_builder;

		Formula gen_formula() const;

		class UnknownErrorException: public std::exception {
			public:
				explicit UnknownErrorException(UnknownErrorType uet);
				UnknownErrorException() = delete;
				~UnknownErrorException() override = default;

				UnknownErrorException(const UnknownErrorException &) = default;
				UnknownErrorException &operator=(const UnknownErrorException &) = default;

				const char * what() const noexcept override;

			private:
				UnknownErrorType uet;
		};
};

#endif // ifndef FORMULA_BUILDER_CLASS_HPP
