#ifndef FT_MALLOC_INTERN_H
#define FT_MALLOC_INTERN_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h> // memcpy, memset

#define TINY_MAX    64
#define SMALL_MAX   3072

typedef struct  s_mlc_block {
    size_t      len;
    uint8_t     is_free;
}               t_mlc_block;

typedef struct  s_mlc_header {
    size_t              tot;
    struct s_mlc_header * next_page;
}               t_mlc_header;

typedef struct  s_mlc_main {
    int             pgsize;
    t_mlc_header    * tn_header;
    t_mlc_header    * sm_header;
    t_mlc_header    * lrg_header;
}               t_mlc_main;

// Utils

// mmap_utils.c
void *mmap_brut(size_t size);

#endif