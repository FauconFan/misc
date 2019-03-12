
#include "FNC.namespace.hpp"

namespace FNC {
    void        delete_tautologies(std::vector<AClause *> * vec) {
        vec->erase(
            std::remove_if(vec->begin(), vec->end(),
                    [](const AClause * acl) -> bool {return (acl->is_tautology());}),
                vec->end()
        );
    }

    void        simplify(std::vector<AClause *> * vec) {
        for (AClause * acl : *vec)
            acl->simplify_clause();
    }

    void        printFNC(const std::vector<AClause *> * vec) {
        std::cout << "FNC [\n";
        for (AClause * ac : *vec)
            std::cout << "\t" << *ac;
        std::cout << "]\n";
    }
}