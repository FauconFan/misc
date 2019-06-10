#include "ft_malloc.h"

void *realloc(void *ptr, size_t len_out) {
    t_mlc_block * blk;
    t_mlc_main * env;
    char    *next;
    size_t len_in;

    if (ptr == NULL)
        return (malloc(len_out));
    env = mlc_main_get();
    next = NULL;
    if (env != NULL) {
        len_in = mlc_main_find_free(env, ptr);
        blk = mlc_main_find_alloc(env, len_out);
        if (blk != NULL) {
            next = (char *)(blk + 1);
            if (len_in != 0) {
                if (len_out > len_in)
                    len_out = len_in;
                for (size_t i = 0; i < len_out; ++i)
                    next[i] = ((char *)ptr)[i];
            }
        }
    }
    return (next);
}
