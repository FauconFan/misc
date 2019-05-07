#include "ft_malloc.h"

void *mmap_brut(size_t size) {
    void    *v;

    v = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (v == MAP_FAILED)
        return (NULL);
    return (v);
}