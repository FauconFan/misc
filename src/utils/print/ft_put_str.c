#include "ft_malloc.h"

void    ft_put_str(char * str) {
    size_t  len;

    len = 0;
    while (str[len])
        len++;
    write(1, str, len);
}

void    ft_put_str_ln(char * str) {
    ft_put_str(str);
    write(1, "\n", 1);
}