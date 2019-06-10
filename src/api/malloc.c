#include "ft_malloc.h"

void *malloc(size_t size) {
    t_mlc_main  *env;
    t_mlc_block *blk;

    if (size == 0)
        return (NULL);
    env = mlc_main_get();
    if (env == NULL)
        return (NULL);
    blk = mlc_main_find_alloc(env, size);
    if (blk == NULL)
        return (NULL);
    return (blk + 1);
}
