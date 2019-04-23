#ifndef DECISION_CLASS_HPP
#define DECISION_CLASS_HPP

#include "libsat.hpp"

enum e_sub_decision_type {
    ASSIGN, // polarity consequence
    RM_CLAUSE,
    RM_LITT,
};

class SubDecision {
    public:
        SubDecision() = delete;
        virtual ~SubDecision();
        SubDecision(const SubDecision &);
        SubDecision &operator=(const SubDecision &);

        e_sub_decision_type get_type() const;

        static SubDecision decision_assign(unsigned int litt_id, bool value);
        static SubDecision decision_rm_clause(unsigned int clause_id);
        static SubDecision decision_rm_litt(unsigned int clause_id, int litt);

        e_sub_decision_type type;
        union {
            struct {
                unsigned int    litt_id;
                bool            value; // Maybe delete this
            }           assign;
            struct {
                unsigned int    clause_id;
            }           rm_clause;
            struct {
                unsigned int    clause_id;
                int             litt;
            }           rm_litt;
        }               u;
    private:
        // assign
        SubDecision(unsigned int litt_id, bool value);
        // rm_clause
        SubDecision(unsigned int clause_id);
        // rm_litt
        SubDecision(unsigned int clause_id, int litt);
};

std::ostream &operator<<(std::ostream &, const SubDecision &);

class Decision {
    public:
        Decision() = delete;
        virtual ~Decision();
        Decision(const Decision &);
        Decision &operator=(const Decision &);

        Decision(unsigned int variable_id, bool value);

        const std::list<SubDecision> & get_consequences() const;

        void add_subdecision(const SubDecision &);

        unsigned int get_variable_id() const;

    private:
        unsigned int _variable_id;
        bool _value; // delete this maybe ?
        // consequences will never be the same !
        std::list<SubDecision>  _consequences;
};

std::ostream &operator<<(std::ostream &, const Decision &);

#endif