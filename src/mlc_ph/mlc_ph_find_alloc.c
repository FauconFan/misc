#include "ft_malloc.h"

void    *mlc_ph_find_alloc(t_mlc_ph * ph, size_t len) {
    t_mlc_block *block;
    void    *v;

    block = (t_mlc_block *) (ph + 1);
    v = mlc_block_find_alloc(block, ph->len_page - sizeof(t_mlc_ph), len);
    if (v != NULL)
        return (v);
    if (ph->next_page == NULL) {
        ph->next_page = mlc_ph_new(len);
        if (ph->next_page == NULL) {
            return (NULL);
        }
    }
    return (mlc_ph_find_alloc(ph->next_page, len));
}