#include "ft_malloc.h"

void        mlc_block_print(t_mlc_block * block, size_t remain) {
    t_mlc_block * next;

    ft_put_str("\tBLOCK => LEN = ");
    ft_put_uint(block->len_block);
    ft_put_str(", IS FREE = ");
    ft_put_str_ln(STR_OF_BOOL(block->is_free));
    if (block->len_block == 0)
        return ;
    if (block->len_block < remain) {
        next = (t_mlc_block *) ((char *)block + block->len_block);
        remain -= block->len_block;
        mlc_block_print(next, remain);
    }
}