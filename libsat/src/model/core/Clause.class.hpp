#ifndef CLAUSE_CLASS_HPP
#define	CLAUSE_CLASS_HPP

#include "libsat.hpp"

class Occ_list;

class Clause
{
	public:
		Clause ();
		virtual~Clause();
		explicit Clause (const std::vector<int> & litts);
		Clause (const Clause & icl);
		Clause &operator=(const Clause & icl);

		// Getters
		const std::set<unsigned int> &  get_pos_litts() const;
		const std::set<unsigned int> &  get_neg_litts() const;
		const std::set<int> &           get_absent_litts() const;
		bool                            is_satisfied() const;

		// Setters
		void                            remove_litt(int);
		void                            add_litt(int);
		void                            set_satisfied(bool b);

		// Builders
		std::set<unsigned int>          build_presence_set() const;
		std::set<int>                   build_litts() const;

		// Predicates
		bool                            is_empty_clause() const;
		bool                            is_two_clause() const;
		int                             is_unit_clause() const;
		int                             presence_litt(int) const;

	private:
		std::set<unsigned int> _pos_litts {};
		std::set<unsigned int> _neg_litts {};
		std::set<int> _absent_litts {};
		bool satisfied {false};
};

std::ostream &operator<<(std::ostream & os, const Clause & icl);

#endif // ifndef IMPL_CLAUSE_CLASS_HPP
