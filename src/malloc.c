#include <ft_malloc.h>
#include <string.h>
#include <errno.h>

static void *alloc_mmap(size_t size) {
    void    *v;
    // v = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    v = mmap(NULL, size + sizeof(size), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (v == MAP_FAILED)
        return (NULL);
    *(size_t *)v = size;
    return (v + sizeof(size));
}

void *malloc(size_t size) {
    if (size == 0)
        return (NULL);
    return (alloc_mmap(size));
}

void free(void * ptr) {
    size_t  len;
    void    *real;

    if (ptr == NULL)
        return ;
    real = ptr - sizeof(len);
    len = *(size_t *)real;
    munmap(real, len + sizeof(len));
}

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

void *realloc(void *ptr, size_t len_out) {
    size_t  len_in;
    void    *real;
    void    *other;

    if (ptr == NULL)
        return (NULL);
    real = ptr - sizeof(len_in);
    len_in = *(size_t *)real;
    other = alloc_mmap(len_out);
    memcpy(other, ptr, (len_in < len_out) ? len_in : len_out);
    munmap(real, len_in + sizeof(len_in));
    return (other);
}

void show_alloc_mem() {
    write(1, "Not implemented yet\n", 20);
}