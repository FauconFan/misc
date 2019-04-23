#ifndef PAIR_CLASS_HPP
#define	PAIR_CLASS_HPP

#include "libsat.hpp"

class Pair{
	public:
		Pair ();
		virtual~Pair ();
		Pair (const Pair &);
		Pair & operator=(const Pair &);
		Pair (unsigned int, unsigned int);

		// Getters
		unsigned int get_left() const;
		unsigned int get_right() const;

		// Setters
		Pair & operator+=(const Pair &);
		Pair & operator-=(const Pair &);

		// Predicates
		bool operator==(const Pair &) const;

	private:
		unsigned int _left {0};
		unsigned int _right {0};
};

std::ostream & operator<<(std::ostream & os, const Pair & p);

#endif // ifndef PAIR_CLASS_HPP
