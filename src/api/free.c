#include "ft_malloc.h"

void free(void * ptr) {
    size_t  len;
    void    *real;

    if (ptr == NULL)
        return ;
    real = ptr - sizeof(len);
    len = *(size_t *)real;
    munmap(real, len + sizeof(len));
}