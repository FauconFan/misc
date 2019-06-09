#include "ft_malloc.h"

static void size_multiple_n(size_t * new_len, size_t n) {
    if (*new_len % n != 0)
        *new_len += n - (*new_len % n);
}

void    size_multiple_16(size_t * new_len) {
    size_multiple_n(new_len, 16);
}

void    size_multiple_page(size_t * new_len) {
    size_multiple_n(new_len, getpagesize());
}