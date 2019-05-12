#include "ft_malloc.h"

void *malloc(size_t size) {
    void    *v;
    size_t  page;

    if (size == 0)
        return (NULL);
    page = size + sizeof(size);
    v = mmap_good_size(&page);
    *(size_t *)v = page - sizeof(size);
    return (v + sizeof(size));
}
