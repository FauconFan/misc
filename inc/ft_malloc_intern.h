#ifndef FT_MALLOC_INTERN_H
#define FT_MALLOC_INTERN_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h> // memcpy, memset

#define TRUE                1
#define FALSE               0

#define STR_OF_BOOL(b)      ((b) ? "true" : "false")

#define TINY_MAX            512
#define SMALL_MAX           3072

#define DEFAULT_MIN_ALLOC   100
#define MULT_PAGE_TINY      4
#define MULT_PAGE_SMALL     16
#define MULT_PAGE_BIG       1
// #define PAGE_BUFFER         10

typedef unsigned char   t_bool;

// mlc_block stands for malloc blocks
typedef struct  s_mlc_block {
    size_t      len_block;
    uint8_t     is_free;
}               t_mlc_block;

#define NEXT_BLOCK(blk) ((t_mlc_block *)((char *)blk + blk->len_block))

// mlc_ph stands for malloc_page_header.
typedef struct  s_mlc_ph {
    struct s_mlc_ph     * next_page;
    size_t              len_page;
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
void          mlc_main_print(t_mlc_main * main);
t_mlc_block * mlc_main_find_alloc(t_mlc_main * main, size_t len);
size_t        mlc_main_find_free(t_mlc_main * main, void * ptr);

t_mlc_ph    * mlc_ph_new(size_t size, size_t mult);
void          mlc_ph_print(t_mlc_ph * ph);
t_mlc_block * mlc_ph_find_alloc(t_mlc_ph * ph, size_t len, size_t mult);
size_t        mlc_ph_find_free(t_mlc_ph * ph, void * ptr);

void          mlc_block_init(void * v, size_t remain_tot);
void          mlc_block_print(t_mlc_block * block, size_t remain);
t_mlc_block * mlc_block_find_alloc(t_mlc_block * block, size_t remain, size_t size);
size_t        mlc_block_find_free(t_mlc_block * block, size_t remain, void * ptr);

// Utils

// mmap_utils.c
void    * mmap_good_size(size_t * size, size_t mult);

// size_utils.c
void    size_multiple_16(size_t * new_len);
void    size_multiple_page(size_t * new_len);

// print utils
void    ft_put_str(char * str);
void    ft_put_str_ln(char * str);
void    ft_put_uint(unsigned long int nb);
void    ft_put_uint16(unsigned long int nb);
void    ft_put_addr(void * v);

#endif