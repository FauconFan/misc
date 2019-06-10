#include "ft_malloc.h"

size_t      mlc_main_find_free(t_mlc_main * main, void * ptr) {
    size_t  res;

    res = mlc_ph_find_free(main->tn_header, ptr);
    if (res != 0)
        return (res);
    res = mlc_ph_find_free(main->sm_header, ptr);
    if (res != 0)
        return (res);
    return (mlc_ph_find_free(main->lrg_header, ptr));
}