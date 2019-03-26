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

		void            set(unsigned int, bool);
		std::unordered_map<unsigned int, bool, std::hash<unsigned int>, std::equal_to<>,
		  std::allocator<std::pair<const unsigned int, bool> > >::const_iterator find(unsigned int) const;
		std::unordered_map<unsigned int, bool, std::hash<unsigned int>, std::equal_to<>,
		  std::allocator<std::pair<const unsigned int, bool> > >::const_iterator end() const;
	// bool         contains(unsigned int) const;

	private:
		std::unordered_map<unsigned int, bool> _distrib {};
};

std::ostream & operator<<(std::ostream & os, const Distrib & d);

#endif // ifndef DISTRIB_CLASS_HPP
