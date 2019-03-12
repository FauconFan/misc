#include "libsat.hpp"

bool    AClause::operator==(const AClause & rhs) const {
    if (this->getType() != rhs.getType())
        return (false);
    switch (this->getType())
    {
        case CLAUSE:
            return (*(dynamic_cast<const Clause *>(this)) == dynamic_cast<const Clause &>(rhs));
		case IMPLCLAUSE:
			return (*(dynamic_cast<const ImplClause *>(this)) == dynamic_cast<const ImplClause &>(rhs));
    }
}

std::ostream &operator<<(std::ostream &os, const AClause & acl) {
    switch (acl.getType())
    {
        case CLAUSE:
            return os << dynamic_cast<const Clause &>(acl);
		case IMPLCLAUSE:
			return os << dynamic_cast<const ImplClause &>(acl);
    }
}
