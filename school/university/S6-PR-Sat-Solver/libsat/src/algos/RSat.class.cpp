#include "libsat.hpp"

bool RSat::is_sat() const{return (this->sat);}

const Distrib & RSat::get_distrib() const{return (this->distrib);}

unsigned int RSat::get_nb_conflict() const{return (this->nb_conflict);}

unsigned int RSat::get_nb_conflict_tot() const{return (this->nb_conflict_tot);}

unsigned int RSat::get_nb_init_clauses() const{return (this->nb_init_clauses);}

unsigned int RSat::get_nb_learnt_clauses() const{return (this->nb_learnt_clauses);}

unsigned int RSat::get_nb_learnt_clauses_tot() const{return (this->nb_learnt_clauses_tot);}

unsigned int RSat::get_nb_forgotten_clauses() const{return (this->nb_forgotten_clauses);}

unsigned int RSat::get_nb_forgotten_clauses_tot() const{return (this->nb_forgotten_clauses_tot);}

unsigned int RSat::get_nb_restart() const{return (this->nb_restart);}

void RSat::set_is_sat(bool isat) {
	this->sat = isat;
}

void RSat::set_distrib(const Distrib & dist) {
	this->distrib = dist;
}

void RSat::set_init_clauses(unsigned int init_clauses) {
	this->nb_init_clauses = init_clauses;
}

void RSat::increase_conflict() {
	this->nb_conflict++;
	this->nb_conflict_tot++;
}

void RSat::increase_learnt_clauses() {
	this->nb_learnt_clauses++;
	this->nb_learnt_clauses_tot++;
}

void RSat::increase_forgotten_clauses() {
	this->nb_forgotten_clauses++;
	this->nb_forgotten_clauses_tot++;
}

void RSat::restart() {
	this->nb_conflict          = 0;
	this->nb_learnt_clauses    = 0;
	this->nb_forgotten_clauses = 0;
	this->nb_restart++;
}

std::ostream &operator<<(std::ostream & os, const RSat & rsat) {
	if (rsat.is_sat() == false) {
		os << "UNSAT" << std::endl;
	}
	else {
		os << "SAT" << std::endl;
		size_t i = 0;

		for (auto p : rsat.get_distrib().get_distrib()) {
			if (i != 0)
				os << " ";
			i++;
			if (p.second == false)
				os << "-";
			os << p.first;
		}
		os << std::endl;
	}
	os << "-- Nb conflict : " << rsat.get_nb_conflict() << std::endl;
	os << "-- Nb conflict (tot) : " << rsat.get_nb_conflict_tot() << std::endl;
	os << "-- Nb init clauses : " << rsat.get_nb_init_clauses() << std::endl;
	os << "-- Nb learnt clauses : " << rsat.get_nb_learnt_clauses() << std::endl;
	os << "-- Nb learnt clauses (tot) : " << rsat.get_nb_learnt_clauses_tot() << std::endl;
	os << "-- Nb forgotten clauses : " << rsat.get_nb_forgotten_clauses() << std::endl;
	os << "-- Nb forgotten clauses (tot) : " << rsat.get_nb_forgotten_clauses_tot() << std::endl;
	os << "-- Nb restart : " << rsat.get_nb_restart() << std::endl;
	return (os);
}
