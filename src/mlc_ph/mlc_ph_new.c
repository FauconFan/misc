#include "ft_malloc.h"

t_mlc_ph    *mlc_ph_new(size_t size) {
    t_mlc_ph    *res;

    res = (t_mlc_ph *)mmap_good_size(&size);
    if (res == NULL)
        return (NULL);
    res->len_page = size - sizeof(t_mlc_ph);
    res->next_page = NULL;
    return (res);
}