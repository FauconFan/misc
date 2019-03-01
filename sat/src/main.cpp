#include "sat.hpp"

int main(void)
{
    std::vector<int>    litts1 = {2, 3, 4, 5};
    std::vector<int>    litts2 = {2, 3, 4, 5, 6, 7, 8};
    Clause c1(litts1);
    Clause c2(litts2);
    std::vector<Clause> cl = {c1, c2};

    FNC fnc(cl);

    std::cout << "Hello World !" << std::endl;
    std::cout << fnc;
    return 0;
}
