#ifndef OCC_LIST_CLASS_HPP
#define	OCC_LIST_CLASS_HPP

#include "libsat.hpp"

class Fnc;

class Occ_list{
	public:
		Occ_list ();
		virtual~Occ_list();
		Occ_list (const Occ_list &);
		Occ_list & operator=(const Occ_list &);

        // Getters
		Pair get_pair(unsigned int) const;

        // Builders
		std::pair<std::vector<unsigned int>, std::vector<unsigned int> > build_solo_polarity() const;
		std::set<unsigned int> build_present_variables() const;

        // Setters
        void set_content(const std::vector<Clause> & clauses);
		void add_pair(unsigned int, const Pair &);
		void sub_pair(unsigned int, const Pair &);

        // Predicates
		bool empty() const;

        // Other
		Occ_list & operator+=(const Occ_list &);
		Occ_list & operator-=(const Occ_list &);

		unsigned int stat_min_occu() const;
		unsigned int stat_max_occu() const;

		void display(std::ostream & os) const;

	private:
		std::unordered_map<unsigned int, Pair> _content {};
};

std::ostream & operator<<(std::ostream & os, const Occ_list & ol);


#endif // ifndef OCC_LIST_CLASS_HPP
