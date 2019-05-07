#include "ft_malloc.h"

void *realloc(void *ptr, size_t len_out) {
    size_t  len_in;
    void    *real;
    void    *other;

    if (ptr == NULL)
        return (NULL);
    real = ptr - sizeof(len_in);
    len_in = *(size_t *)real;
    other = malloc(len_out);
    if (len_out < len_in) {
        memcpy(other, ptr, len_out);
    }
    else {
        memcpy(other, ptr, len_in);
        memset(other + len_in, 0, len_out - len_in);
    }
    munmap(real, len_in + sizeof(len_in));
    return (other);
}