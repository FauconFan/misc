
#ifndef FNC_CLASS_HPP
#define FNC_CLASS_HPP

#include "libsat.hpp"

namespace FNC {
    void                delete_tautologies(std::vector<AClause *> * vec);
    Occ_list                simplify(std::vector<AClause *> * vec);

    void                printFNC(const std::vector<AClause *> * vec);
};

namespace FNC {
    template<class T>
    std::vector<T *> *convert(const std::vector<AClause *> * vec) {
        std::vector<T *> * res = new std::vector<T *>();

        for (const AClause * acl : *vec) {
            switch (acl->getType())
            {
                case CLAUSE:
                    res->push_back(new T(*dynamic_cast<const Clause *>(acl)));
                    break ;
                case IMPLCLAUSE:
                    res->push_back(new T(*dynamic_cast<const ImplClause *>(acl)));
                    break ;
            }
        }
        return (res);
    }
};

#endif
