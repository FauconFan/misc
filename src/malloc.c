#include "ft_malloc.h"

void *malloc(size_t size) {
    void    *v;

    if (size == 0)
        return (NULL);
    v = mmap_brut(size + sizeof(size));
    *(size_t *)v = size;
    return (v + sizeof(size));
}
