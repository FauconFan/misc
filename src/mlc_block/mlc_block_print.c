#include "ft_malloc.h"

void        mlc_block_print(t_mlc_block * block, size_t remain) {
    t_mlc_block * next;

    ft_put_addr(block);
    ft_putstr("block, len  ");
    ft_put_uint(block->len_block);
    ft_putstr("block, free ");
    ft_putstr(STR_OF_BOOL(block->is_free));
    ft_putstr("\n");
    if (block->len_block == 0)
        return ;
    if (block->len_block < remain) {
        next = (t_mlc_block *) ((char *)block + block->len_block);
        remain -= block->len_block;
        mlc_block_print(next, remain);
    }
}