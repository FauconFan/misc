
#include "FNC.namespace.hpp"

namespace FNC {
    void        delete_tautologies(std::vector<AClause *> * vec) {
        vec->erase(
            std::remove_if(vec->begin(), vec->end(),
                    [](const AClause * acl) -> bool {return (acl->is_tautology());}),
                vec->end()
        );
    }

    Occ_list        simplify(std::vector<AClause *> * vec) {
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
}
