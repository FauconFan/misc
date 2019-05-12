#include "ft_malloc.h"

static void *mmap_brut(size_t size) {
    void    *v;

    v = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (v == MAP_FAILED)
        return (NULL);
    return (v);
}

void    * mmap_good_size(size_t * size) {
    int pgsize;
    void * v;

    pgsize = getpagesize();
    if (pgsize <= 0 || size == NULL || *size == 0)
        return (NULL);
    if (*size % pgsize != 0) {
        *size += (pgsize - (*size % pgsize));
    }
    v = mmap_brut(*size);
    if (v == NULL)
        *size = 0;
    return (v);
}