#include "ft_malloc.h"

static t_mlc_block * search(t_mlc_block * block, size_t remain, size_t size) {
    size_t len_next_block;

    if (block->is_free && size <= block->len_block) {
        block->is_free = FALSE;
        len_next_block = block->len_block - size;
        block->len_block = size;
        if (len_next_block != 0)
            mlc_block_init((char *)block + block->len_block, len_next_block);
        return (block);
    }
    if (remain > block->len_block)
        return (search(NEXT_BLOCK(block), remain - block->len_block, size));
    return (NULL);
}

t_mlc_block    * mlc_block_find_alloc(t_mlc_block * block, size_t remain, size_t size) {
    return (search(block, remain, size));
}
