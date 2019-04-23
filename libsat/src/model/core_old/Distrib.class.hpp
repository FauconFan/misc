#ifndef DISTRIB_CLASS_HPP
#define	DISTRIB_CLASS_HPP

#include "libsat.hpp"

class Distrib
{
	public:
		Distrib();
		explicit Distrib(const Occ_list &);
		Distrib(const Distrib &);
		Distrib &operator=(const Distrib &);
		virtual~Distrib();

		const std::unordered_map<unsigned int, bool> * getDistrib() const;

		bool            get(unsigned int) const;
		void            set(unsigned int, bool);
		std::unordered_map<unsigned int, bool, std::hash<unsigned int>, std::equal_to<>,
		  std::allocator<std::pair<const unsigned int, bool> > >::const_iterator find(unsigned int) const;
		std::unordered_map<unsigned int, bool, std::hash<unsigned int>, std::equal_to<>,
		  std::allocator<std::pair<const unsigned int, bool> > >::const_iterator end() const;

		void finish();

	private:
		std::unordered_map<unsigned int, bool> _distrib {};
		std::set<unsigned int> _present_variables {};
};

std::ostream & operator<<(std::ostream & os, const Distrib & d);

#endif // ifndef DISTRIB_CLASS_HPP
