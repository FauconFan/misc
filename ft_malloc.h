#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

void show_alloc_mem();

#endif
