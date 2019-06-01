#include "libsat.hpp"

SubDecision::~SubDecision() = default;

SubDecision::SubDecision(const SubDecision & rhs) {
	*this = rhs;
}

SubDecision &SubDecision::operator=(const SubDecision & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		switch (rhs.type) {
			case ASSIGN:
				this->u.assign.litt_id = rhs.u.assign.litt_id;
				this->u.assign.value   = rhs.u.assign.value;
			case RM_CLAUSE:
				this->u.rm_clause.clause_id = rhs.u.rm_clause.clause_id;
				break;

			case RM_LITT:
				this->u.rm_litt.clause_id = rhs.u.rm_litt.clause_id;
				this->u.rm_litt.litt      = rhs.u.rm_litt.litt;
				break;
		}
	}
	return (*this);
}

// assign
SubDecision::SubDecision(unsigned int litt_id, bool value)
	: type(ASSIGN) {
	u.assign.litt_id = litt_id;
	u.assign.value   = value;
}

// rm_clause
SubDecision::SubDecision(unsigned int clause_id)
	: type(RM_CLAUSE) {
	u.rm_clause.clause_id = clause_id;
}

// rm_litt
SubDecision::SubDecision(unsigned int clause_id, int litt)
	: type(RM_LITT) {
	u.rm_litt.clause_id = clause_id;
	u.rm_litt.litt      = litt;
}

e_sub_decision_type SubDecision::get_type() const{
	return (this->type);
}

bool SubDecision::has_clause_id(unsigned int clause_id) const{
	switch (this->type) {
		case ASSIGN:
			return (false);

		case RM_CLAUSE:
			return (this->u.rm_clause.clause_id == clause_id);

		case RM_LITT:
			return (this->u.rm_litt.clause_id == clause_id);
	}
}

unsigned int SubDecision::assign_get_litt() const{
	return (this->u.assign.litt_id);
}

bool SubDecision::assign_get_value() const{
	return (this->u.assign.value);
}

unsigned int SubDecision::rm_clause_get_clause_id() const{
	return (this->u.rm_clause.clause_id);
}

unsigned int SubDecision::rm_litt_get_clause_id() const{
	return (this->u.rm_litt.clause_id);
}

int SubDecision::rm_litt_get_litt() const{
	return (this->u.rm_litt.litt);
}

SubDecision SubDecision::decision_assign(unsigned int litt_id, bool value) {
	return (SubDecision(litt_id, value));
}

SubDecision SubDecision::decision_rm_clause(unsigned int clause_id) {
	return (SubDecision(clause_id));
}

SubDecision SubDecision::decision_rm_litt(unsigned int clause_id, int litt) {
	return (SubDecision(clause_id, litt));
}

std::ostream &operator<<(std::ostream & os, const SubDecision & sd) {
	os << "Subdecision:";
	switch (sd.get_type()) {
		case ASSIGN:
			os << "Assign " << sd.assign_get_litt() << "\n";
			break;
		case RM_CLAUSE:
			os << "Rm clause " << sd.rm_clause_get_clause_id() << "\n";
			break;
		case RM_LITT:
			os << "Rm litt " << sd.rm_litt_get_clause_id() << " " << sd.rm_litt_get_litt() << "\n";
			break;
	}
	return os;
}

Decision::~Decision() = default;

Decision::Decision(const Decision & rhs) {
	*this = rhs;
}

Decision &Decision::operator=(const Decision & rhs) {
	if (this != &rhs) {
		this->_variable_id  = rhs._variable_id;
		this->_value        = rhs._value;
		this->_consequences = rhs._consequences;
	}
	return (*this);
}

Decision::Decision(unsigned int variable_id, bool value)
	: _variable_id(variable_id), _value(value)
{}

const std::list<SubDecision> & Decision::get_consequences() const{
	return (this->_consequences);
}

void Decision::add_subdecision(const SubDecision & sd) {
	this->_consequences.push_front(sd);
}

unsigned int Decision::get_variable_id() const{
	return (this->_variable_id);
}

void Decision::remove_subdecision_containing(unsigned int id_clause) {
	auto p = std::remove_if(
			this->_consequences.begin(),
			this->_consequences.end(),
			[id_clause](SubDecision & subd) -> bool{
		return (subd.has_clause_id(id_clause));
	});

	(void) p;
}

bool Decision::get_value() const{
	return (this->_value);
}

std::ostream &operator<<(std::ostream & os, const Decision & dec) {
	os << "Decision " << dec.get_variable_id() << "\n";
	for (const SubDecision & subdec : dec.get_consequences()) {
		os << subdec;
	}
	return (os);
}
