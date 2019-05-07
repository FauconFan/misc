#include "test.h"
#include <stdlib.h>

int main()
{
    start_test();
    int i;
    char *addr;

    i = 0;
    while (i < 1024)
    {
        i++;
    }
    end_test();
    return (0);
}