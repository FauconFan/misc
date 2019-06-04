#include "ft_malloc.h"

t_mlc_ph    *mlc_ph_new(size_t size) {
    t_mlc_ph    *res;

    res = (t_mlc_ph *)mmap_good_size(&size);
    if (res == NULL)
        return (NULL);
    res->len_page = size;
    res->next_page = NULL;
    mlc_block_init(res + 1, res->len_page - sizeof(t_mlc_ph));
    return (res);
}