#include "ft_malloc.h"

void    ft_put_addr(void * v) {
    ft_put_str("0x");
    ft_put_uint((unsigned long int)v);
}