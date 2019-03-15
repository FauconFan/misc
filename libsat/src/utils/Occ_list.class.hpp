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

		Occ_list & operator += (const Occ_list &);
		Occ_list & operator -= (const Occ_list &);

		const std::unordered_map<unsigned int, Pair> * getContent () const;
		Pair getPair (unsigned int) const;

		void addPair (unsigned int, const Pair);
		bool empty() const;

	private:
		std::unordered_map<unsigned int, Pair> _content;
};

std::ostream & operator<< (std::ostream & os, const Occ_list & ol);
std::ostream & operator<< (std::ostream & os, const Distrib & d);


#endif
