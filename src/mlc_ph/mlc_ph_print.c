#include "ft_malloc.h"

void        mlc_print(t_mlc_ph * ph) {
    t_mlc_block *blk;

    ft_putstr("===================\n");
    ft_putstr("mlc print ph : ");
    ft_put_addr(ph);
    ft_putstr("size page : ");
    ft_put_uint(ph->len_page);
    blk = (t_mlc_block *) (ph + 1);
    mlc_block_print(blk, ph->len_page - sizeof(t_mlc_ph));
    ft_putstr("===================\n");
}