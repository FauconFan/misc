#include "sat.hpp"

int main(int argc, char **argv)
{
    if (argc == 2) {
        FNC     *fnc = getInputFNC(argv[1]);

        if (fnc != NULL) {
            std::cout << *fnc;
            delete fnc;
        }
    }
    else
        return (1);
    return (0);
}
