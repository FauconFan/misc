#ifndef OCC_LIST_CLASS_HPP
#define OCC_LIST_CLASS_HPP

#include "libsat.hpp"

class ImplClause;

class Occ_list {
	public:
		Occ_list ();
		Occ_list (const Occ_list &);
		Occ_list (const std::vector<ImplClause *>);
		virtual ~Occ_list();

		Occ_list & operator=(const Occ_list &);

		Occ_list & operator += (const Occ_list &);
		Occ_list & operator -= (const Occ_list &);

		Pair getPair (unsigned int) const;

		void addPair (unsigned int, const Pair);
		bool empty() const;

		unsigned int getMinOccu() const;
		unsigned int getMaxOccu() const;

		std::pair<std::vector<unsigned int>, std::vector<unsigned int>> getSoloPolarity() const;

		void display(std::ostream & os) const;

	private:
		std::unordered_map<unsigned int, Pair> _content;
};

std::ostream & operator<< (std::ostream & os, const Occ_list & ol);


#endif
