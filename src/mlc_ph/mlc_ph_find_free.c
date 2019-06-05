#include "ft_malloc.h"

t_bool      mlc_ph_find_free(t_mlc_ph * ph, void * ptr) {
    t_mlc_block *block;
    size_t  remain;

    if (ph == NULL || ptr == NULL)
        return (FALSE);
    block = (t_mlc_block *) (ph + 1);
    remain = ph->len_page - sizeof(t_mlc_ph);
    if (mlc_block_find_free(block, remain, ptr))
        return (TRUE);
    return (mlc_ph_find_free(ph->next_page, ptr));
}