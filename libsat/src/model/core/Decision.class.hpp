#ifndef DECISION_CLASS_HPP
#define	DECISION_CLASS_HPP

#include "libsat.hpp"

enum e_sub_decision_type{
	ASSIGN, // polarity consequence
	RM_CLAUSE,
	RM_LITT,
};

class SubDecision{
	public:
		SubDecision() = delete;
		virtual~SubDecision();
		SubDecision(const SubDecision &);
		SubDecision &operator=(const SubDecision &);

		e_sub_decision_type get_type() const;

		static SubDecision decision_assign(unsigned int litt_id, bool value);
		static SubDecision decision_rm_clause(unsigned int clause_id);
		static SubDecision decision_rm_litt(unsigned int clause_id, int litt);

		unsigned int        assign_get_litt() const;
		bool                assign_get_value() const;

		unsigned int        rm_clause_get_clause_id() const;

		unsigned int        rm_litt_get_clause_id() const;
		int                 rm_litt_get_litt() const;
	private:
		e_sub_decision_type type {};
		union {
			struct {
				unsigned int litt_id;
				bool         value;
			} assign;
			struct {
				unsigned int clause_id;
			} rm_clause;
			struct {
				unsigned int clause_id;
				int          litt;
			} rm_litt;
		} u {};

		// assign
		SubDecision(unsigned int litt_id, bool value);
		// rm_clause
		explicit SubDecision(unsigned int clause_id);
		// rm_litt
		SubDecision(unsigned int clause_id, int litt);
};

std::ostream &operator<<(std::ostream &, const SubDecision &);

class Decision{
	public:
		Decision() = delete;
		virtual~Decision();
		Decision(const Decision &);
		Decision &operator=(const Decision &);

		Decision(unsigned int variable_id, bool value);

		const std::list<SubDecision> & get_consequences() const;

		void add_subdecision(const SubDecision &);

		unsigned int get_variable_id() const;
		bool get_value() const;

	private:
		unsigned int _variable_id {0};
		bool _value {true};
		// consequences will never be the same !
		std::list<SubDecision> _consequences {};
};

std::ostream &operator<<(std::ostream &, const Decision &);

#endif // ifndef DECISION_CLASS_HPP
