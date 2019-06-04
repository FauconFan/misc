#include "ft_malloc.h"

t_bool      mlc_ph_find_free(t_mlc_ph * ph, void * ptr) {
    t_mlc_block *block;

    block = (t_mlc_block *) (ph + 1);
    return (mlc_block_find_free(block, ph->len_page - sizeof(t_mlc_ph), ptr));
}