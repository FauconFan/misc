#include "test.h"
#include <ft_malloc.h>

int main()
{
    start_test();
    malloc(1024);
    malloc(1024 * 32);
    malloc(1024 * 1024);
    malloc(1024 * 1024 * 16);
    malloc(1024 * 1024 * 128);
    show_alloc_mem();
    end_test();
    return (0);
}
