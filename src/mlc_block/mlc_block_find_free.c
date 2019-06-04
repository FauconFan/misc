#include "ft_malloc.h"

static t_bool fusion_with_next(t_mlc_block * prev, size_t remain) {
    if (remain <= prev->len_block)
        return (FALSE);
    if (prev->is_free == FALSE || NEXT_BLOCK(prev)->is_free == FALSE)
        return (FALSE);
    prev->len_block += NEXT_BLOCK(prev)->len_block;
    return (TRUE);
}

static t_bool search_free(t_mlc_block * prev, size_t remain, void * ptr) {
    if (remain <= prev->len_block)
        return (FALSE);
    if (ptr == (void *)(NEXT_BLOCK(prev) + 1)) {
        NEXT_BLOCK(prev)->is_free = TRUE;
        if (fusion_with_next(prev, remain))
            fusion_with_next(prev, remain);
        else
            fusion_with_next(NEXT_BLOCK(prev), remain - prev->len_block);
        return (TRUE);
    }
    return (search_free(NEXT_BLOCK(prev), remain - prev->len_block, ptr));
}

t_bool  mlc_block_find_free(t_mlc_block * block, size_t remain, void * ptr) {
    if (ptr == (void *)(block + 1)) {
        if (remain <= block->len_block) {
            block->is_free = TRUE;
        }
        else if (NEXT_BLOCK(block)->is_free) {
            block->is_free = TRUE;
            block->len_block += NEXT_BLOCK(block)->len_block;
        }
        else {
            block->is_free = TRUE;
        }
        return (TRUE);
    }
    return (search_free(block, remain, ptr));
}