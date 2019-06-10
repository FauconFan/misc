#include "ft_malloc.h"

static t_mlc_block *alloc_page_then_search(t_mlc_ph ** page_ptr, size_t len, size_t mult) {
    if (*page_ptr == NULL) {
        *page_ptr = mlc_ph_new(len, mult);
        if (*page_ptr == NULL)
            return (NULL);
    }
    return (mlc_ph_find_alloc(*page_ptr, len, mult));
}

t_mlc_block    *mlc_main_find_alloc(t_mlc_main * main, size_t len) {
    len += sizeof(t_mlc_block);
    size_multiple_16(&len);
    if (len <= TINY_MAX)
        return (alloc_page_then_search(&main->tn_header, len, MULT_PAGE_TINY));
    if (len <= SMALL_MAX)
        return (alloc_page_then_search(&main->sm_header, len, MULT_PAGE_SMALL));
    size_multiple_page(&len);
    return (alloc_page_then_search(&main->lrg_header, len - sizeof(t_mlc_ph), MULT_PAGE_BIG));
}
