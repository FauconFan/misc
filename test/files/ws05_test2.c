#include "test.h"
#include <ft_malloc.h>

int main()
{
    // start_test();
    int i;
    char *addr;

    i = 0;
    while (i < 2)
    {
        write(1, "=====================\n", 22);
        show_alloc_mem();
        addr = (char*)malloc(1024);
        addr[0] = 42;
        show_alloc_mem();
        free(addr);
        show_alloc_mem();
        i++;
    }
    // end_test();
    return (0);
}