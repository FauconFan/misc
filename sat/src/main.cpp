#include "sat.hpp"

int main(int argc, char **argv)
{
    if (argc == 2) {
        std::vector<AClause *> *fnc = getInputFNC(argv[1]);

        if (fnc != NULL) {
            FNC::printFNC(fnc);
            FNC::delete_tautologies(fnc);
            FNC::simplify(fnc);
            FNC::printFNC(fnc);

            std::vector<ImplClause *> *impl_clauses = FNC::convert<ImplClause>(fnc);

            FNC::printFNC(reinterpret_cast<std::vector<AClause *> *>(impl_clauses));

            delete fnc;
        }
    }
    else
        return (1);
    return (0);
}
