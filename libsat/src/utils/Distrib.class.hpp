#ifndef DISTRIB_CLASS_HPP
#define	DISTRIB_CLASS_HPP

#include "libsat.hpp"

class Distrib
{
	public:
		Distrib();
		Distrib(const Distrib &) = delete;
		Distrib &operator=(const Distrib &) = delete;
		virtual~Distrib();

		const std::unordered_map<unsigned int, bool> * getDistrib() const;

		void        set(unsigned int, bool);

	private:
		std::unordered_map<unsigned int, bool> _distrib;
};

std::ostream & operator<<(std::ostream & os, const Distrib & d);

#endif // ifndef DISTRIB_CLASS_HPP
