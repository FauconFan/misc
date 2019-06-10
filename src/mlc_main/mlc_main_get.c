#include "ft_malloc.h"

static int verify_defines(void) {
    if (TINY_MAX <= 0)
        return (1);
    if (TINY_MAX >= SMALL_MAX)
        return (1);
    if (TINY_MAX % 8 != 0)
        return (1);
    if (SMALL_MAX % 8 != 0)
        return (1);
    return (0);
}

static size_t process_nb_pages_min(
                int pgsize,
                size_t min) {
    return (1 + (sizeof(t_mlc_block) + min) * DEFAULT_MIN_ALLOC / (pgsize - sizeof(t_mlc_ph)));
}

static void process_nb_pages_init(
                int pgsize,
                size_t * npage_tn,
                size_t * npage_sm) {
    size_t  min_size;

    min_size = TINY_MAX - 1;
    size_multiple_16(&min_size);
    *npage_tn = process_nb_pages_min(pgsize, min_size) * pgsize;
    min_size = SMALL_MAX - 1;
    size_multiple_16(&min_size);
    *npage_sm = process_nb_pages_min(pgsize, min_size) * pgsize;
}

t_mlc_main  * mlc_main_get(void) {
    size_t  len;
    size_t  page_size[2];

    if (g_mlc_main == NULL) {
        if (verify_defines() == 1)
            return (NULL);
        process_nb_pages_init(getpagesize(), page_size + 0, page_size + 1);
        len = sizeof(*g_mlc_main);
        if ((g_mlc_main = mmap_good_size(&len, 1)) == NULL)
            return (NULL);
        g_mlc_main->len_main = len;
        g_mlc_main->tn_header = mlc_ph_new(page_size[0], 1);
        g_mlc_main->sm_header = mlc_ph_new(page_size[1], 1);
        g_mlc_main->lrg_header = NULL;
        if (g_mlc_main->tn_header == NULL || g_mlc_main->sm_header == NULL) {
            if (g_mlc_main->tn_header != NULL)
                munmap(g_mlc_main->sm_header, page_size[1]);
            if (g_mlc_main->sm_header != NULL)
                munmap(g_mlc_main->tn_header, page_size[0]);
            munmap(g_mlc_main, len);
            return (NULL);
        }
        // for (int i = 0; i < PAGE_BUFFER; ++i)
        //     g_mlc_main->buffer[i] = NULL;
    }
    return (g_mlc_main);
}

t_mlc_main   * g_mlc_main = NULL;
