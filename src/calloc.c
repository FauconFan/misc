#include "ft_malloc.h"

void *calloc(size_t nmemb, size_t size) {
    void * v;
    size_t  len;
    
    len = nmemb * size;
    v = malloc(len);
    if (v == NULL)
        return (NULL);
    memset(v, 0, len);
    return (v);
}