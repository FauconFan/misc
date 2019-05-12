#ifndef FT_MALLOC_INTERN_H
#define FT_MALLOC_INTERN_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h> // memcpy, memset

#define TRUE                1
#define FALSE               0

#define TINY_MAX            64
#define SMALL_MAX           3072

#define DEFAULT_MIN_ALLOC   100
// #define PAGE_BUFFER         10

// mlc_block stands for malloc blocks
typedef struct  s_mlc_block {
    size_t      len_block;
    uint8_t     is_free;
}               t_mlc_block;

// mlc_ph stands for malloc_page_header.
typedef struct  s_mlc_ph {
    size_t              len_page;
    struct s_mlc_ph     * next_page;
}               t_mlc_ph;

// Global structures
typedef struct  s_mlc_main {
    int         len_main;
    t_mlc_ph    * tn_header;
    t_mlc_ph    * sm_header;
    t_mlc_ph    * lrg_header;
    // t_mlc_ph    * buffer[PAGE_BUFFER];
}               t_mlc_main;

extern t_mlc_main   * g_mlc_main;

t_mlc_main  * mlc_main_get(void);

t_mlc_ph    *mlc_ph_new(size_t size);

void        mlc_block_init(void * v, size_t remain_tot);

// Utils

// mmap_utils.c
void    * mmap_good_size(size_t * size);

// print_utils.c
void    ft_putstr(char * str);
void    ft_put_uint(unsigned int nb);

#endif