#include "FNC.namespace.hpp"

namespace FNC {
	Occ_list    delete_tautologies(std::vector<AClause *> * vec) {
		Occ_list res;

		for (auto i = vec->begin(); i != vec->end(); i++) {
			if ((*i)->is_tautology()) {
				res += (*i)->get_occ_list();
				i--;
				vec->erase(i + 1);
			}
		}

		return res;
	}

	Occ_list    simplify(std::vector<AClause *> * vec) {
		Occ_list res;

		for (AClause * acl : *vec)
			res += acl->simplify_clause();

		return res;
	}

	void        printFNC(const std::vector<AClause *> * vec) {
		std::cout << "FNC [\n";

		for (AClause * ac : *vec)
			std::cout << "\t" << *ac;
		std::cout << "]\n";
	}

	bool        contains(const std::vector<AClause *> * vec, const AClause * aclause) {
		for (AClause * ac : *vec) {
			if (*ac == *aclause)
				return true;
		}

		return false;
	}

	Occ_list    delete_if_contains(std::vector<AClause *> * vec, int val) {
		Occ_list res;

		for (auto i = vec->begin(); i != vec->end(); i++) {
			int litt_side = (*i)->contains_litt(val);
			if (litt_side != 0) {
				res += (*i)->get_occ_list();
				i--;
				vec->erase(i + 1);
			}
		}

		return res;
	}
}
