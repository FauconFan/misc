#ifndef FNCC_CLASS_HPP
#define	FNCC_CLASS_HPP

#include "libsat.hpp"

class FNCC{
	public:
		FNCC();
		FNCC(const FNCC &);
		FNCC &operator=(const FNCC &);
		explicit FNCC(const std::vector<ImplClause> &);
		virtual~FNCC();

		bool                        empty() const;
		void                        add_clause(const ImplClause &);
		void                        add_fnc(const FNCC &);
		std::vector<ImplClause>     get_implclauses();

		Occ_list        build_occ_list() const;

		Occ_list        delete_tautologies();
		Occ_list        simplify();
		Occ_list        delete_if_contains(int);
		bool            contains(const ImplClause &);

		void            display(std::ostream &) const;


	private:
		std::vector<ImplClause> _clauses {};
		bool _is_impl_clauses {false};

		void                    transform_to_impl_clauses();
};

std::ostream    &operator<<(std::ostream &, const FNCC &);

#endif // ifndef FNCC_CLASS_HPP
