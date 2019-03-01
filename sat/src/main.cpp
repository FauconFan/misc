#include "sat.hpp"

int main(void)
{
    std::vector<int>    litts1 = {2, 3, 4, 5};
    std::vector<int>    litts2 = {2, 3, 4, 5, 6, 7, 8};
    Clause  cl1(litts1);
    Clause  cl2(litts2);

    std::cout << "Hello World !" << std::endl;
    std::cout << cl1 << cl2;
    return 0;
}
