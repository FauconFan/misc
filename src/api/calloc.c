#include "ft_malloc.h"

void *calloc(size_t nmemb, size_t size) {
    char * v;
    
    v = malloc(nmemb * size);
    for (size_t i = 0; i < nmemb * size; ++i) {
        v[i] = 0;
    }
    return (v);
}