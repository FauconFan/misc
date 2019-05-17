#ifndef IPAIR_CLASS_HPP
#define	IPAIR_CLASS_HPP

#include "libsat.hpp"

class IPair{
	public:
		IPair ();
		virtual~IPair ();
		IPair (const IPair &);
		IPair & operator=(const IPair &);
		IPair (unsigned int, unsigned int);

		// Getters
		unsigned int get_left() const;
		unsigned int get_right() const;

		// Predicates
		bool operator==(const IPair &) const;

	private:
		unsigned int _left {0};
		unsigned int _right {0};
};

std::ostream & operator<<(std::ostream & os, const IPair & p);

#endif // ifndef IPAIR_CLASS_HPP
