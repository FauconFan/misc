#include "ft_malloc.h"

void        mlc_ph_print(t_mlc_ph * ph) {
    t_mlc_block *blk;

    if (ph == NULL)
        return ;
    ft_put_str("PAGE => ");
    ft_put_addr(ph);
    ft_put_str(", LEN = ");
    ft_put_uint(ph->len_page);
    ft_put_str_ln("");
    blk = (t_mlc_block *) (ph + 1);
    mlc_block_print(blk, ph->len_page - sizeof(t_mlc_ph));
    mlc_ph_print(ph->next_page);
}