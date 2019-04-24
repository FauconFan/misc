#ifndef OCC_LIST_CLASS_HPP
#define	OCC_LIST_CLASS_HPP

#include "libsat.hpp"

class Occ_list{
	public:
		Occ_list ();
		virtual~Occ_list();
		Occ_list (const Occ_list &);
		Occ_list & operator=(const Occ_list &);

		// Getters
		const Pair get_count(unsigned int) const;
		const std::set<unsigned int> &get_pos_occu(unsigned int) const;
		const std::set<unsigned int> &get_neg_occu(unsigned int) const;

		// Builders
		std::pair<std::vector<unsigned int>, std::vector<unsigned int> > build_solo_polarity() const;
		std::set<unsigned int> build_present_variables() const;

		// Setters
		void set_content(const std::vector<Clause> & clauses);
		void add_clause_id(unsigned int litt_id, unsigned int clause_id, bool side);
		void add_clause_id(const std::set<int> & sint, unsigned int clause_id);
		void remove_clause_id(unsigned int litt_id, unsigned int clause_id, bool side);
		void remove_clause_id(const std::set<int> & sint, unsigned int clause_id);

		// Predicates
		bool empty() const;

		unsigned int stat_min_occu() const;
		unsigned int stat_max_occu() const;

		void display(std::ostream & os) const;

	private:
		std::unordered_map<unsigned int,
		  std::pair<
			  std::set<unsigned int>,
			  std::set<unsigned int>
		  >
		> _content {};
};

std::ostream & operator<<(std::ostream & os, const Occ_list & ol);


#endif // ifndef OCC_LIST_CLASS_HPP
