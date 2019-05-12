#ifndef FT_MALLOC_INTERN_H
#define FT_MALLOC_INTERN_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h> // memcpy, memset

#define TINY_MAX    64
#define SMALL_MAX   3072

#define PAGE_BUFFER 10

typedef struct  s_mlc_block {
    size_t      len_block;
    uint8_t     is_free;
}               t_mlc_block;

// mlc_ph stands for malloc_page_header.
typedef struct  s_mlc_ph {
    size_t              len_page;
    struct s_mlc_ph     * next_page;
}               t_mlc_ph;

typedef struct  s_mlc_main {
    int         len_main;
    t_mlc_ph    * tn_header;
    t_mlc_ph    * sm_header;
    t_mlc_ph    * lrg_header;
    t_mlc_ph    * buffer[PAGE_BUFFER];
}               t_mlc_main;

extern t_mlc_main   * g_mlc_main;

// Utils

// mmap_utils.c
void    * mmap_good_size(size_t * size);

#endif