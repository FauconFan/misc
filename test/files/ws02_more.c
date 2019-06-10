#include "test.h"
#include <ft_malloc.h>

int main()
{
    start_test();
    int i;
    char *addr;

    i = 0;
    while (i < 1024)
    {
        addr = (char*)malloc(1024);
        addr[0] = 42;
        i++;
    }
    show_alloc_mem();
    end_test();
    return (0);
} 