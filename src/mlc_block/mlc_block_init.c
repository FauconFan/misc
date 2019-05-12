#include "ft_malloc.h"

void        mlc_block_init(void * v, size_t remain_tot) {
    t_mlc_block * head_block;

    head_block = (t_mlc_block *) v;
    head_block->len_block = remain_tot - sizeof(t_mlc_block);
    head_block->is_free = TRUE;
}