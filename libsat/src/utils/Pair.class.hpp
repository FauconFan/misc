#ifndef PAIR_CLASS_HPP
#define	PAIR_CLASS_HPP

#include "libsat.hpp"

class Pair{
	public:
		Pair ();
		Pair (const Pair &);
		Pair (unsigned int, unsigned int);
		virtual~Pair ();

		Pair & operator=(const Pair &);

		Pair & operator+=(const Pair &);
		Pair & operator-=(const Pair &);
		bool operator==(const Pair &) const;

		unsigned int getLeft() const;
		unsigned int getRight() const;

	private:
		unsigned int _left {0};
		unsigned int _right {0};
};

std::ostream & operator<<(std::ostream & os, const Pair & p);

#endif // ifndef PAIR_CLASS_HPP
