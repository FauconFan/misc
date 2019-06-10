#include "test.h"
#include <ft_malloc.h>

int main()
{
    start_test();
    char *addr;

    addr = (char *)malloc(1024);
    show_alloc_mem();
    free(addr);
    show_alloc_mem();
    end_test();
}