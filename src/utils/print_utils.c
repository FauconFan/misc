#include "ft_malloc.h"

void    ft_putstr(char * str) {
    size_t  len;

    len = 0;
    while (str[len])
        len++;
    write(1, str, len);
}

void    ft_put_uint(unsigned int nb) {
    size_t l;
    size_t t;
    char buff[42];

    for (size_t i = 0; i < 42; ++i)
        buff[i] = 0;
    l = 1;
    t = nb;
    while (t /= 10)
        ++l;
    t = l;
    buff[l] = '\0';
    while (t--)
    {
        buff[t] = nb % 10 + '0';
        nb /= 10;
    }
    buff[l] = '\n';
    l++;
    write(1, buff, l);
}