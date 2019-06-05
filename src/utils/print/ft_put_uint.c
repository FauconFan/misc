#include "ft_malloc.h"

/**
 *  We assume that len of base is no greater than 16 and greater than 1
 */
static void    ft_put_uint_base(unsigned long int nb, char * base) {
    size_t lbase;
    size_t l;
    size_t t;
    char buff[42];

    for (size_t i = 0; i < 42; ++i)
        buff[i] = 0;
    lbase = 0;
    while (base[lbase] != 0)
        ++lbase;
    if ((lbase > 1 && lbase <= 16) == 0)
        return ;
    l = 1;
    t = nb;
    while (t /= lbase)
        ++l;
    t = l;
    buff[l] = '\0';
    while (t--)
    {
        buff[t] = base[nb % lbase];
        nb /= lbase;
    }
    write(1, buff, l);
}

void    ft_put_uint(unsigned long int nb) {
    ft_put_uint_base(nb, "0123456789");
}

void    ft_put_uint16(unsigned long int nb) {
    ft_put_uint_base(nb, "0123456789ABCDEF");
}