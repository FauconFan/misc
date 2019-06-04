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
    *npage_tn = process_nb_pages_min(pgsize, 1) * pgsize;
    *npage_sm = process_nb_pages_min(pgsize, TINY_MAX + 1) * pgsize;
}

t_mlc_main  * mlc_main_get(void) {
    size_t  len;
    size_t  page_size[2];

    if (g_mlc_main == NULL) {
        if (verify_defines() == 1)
            return (NULL);
        process_nb_pages_init(getpagesize(), page_size + 0, page_size + 1);
        len = sizeof(*g_mlc_main);
        if ((g_mlc_main = mmap_good_size(&len)) == NULL)
            return (NULL);
        g_mlc_main->len_main = len;
        g_mlc_main->tn_header = mlc_ph_new(page_size[0]);
        g_mlc_main->sm_header = mlc_ph_new(page_size[1]);
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
    mlc_print(g_mlc_main->tn_header);
    void *v1 = mlc_ph_find_alloc(g_mlc_main->tn_header, 2);
    void *v2 = mlc_ph_find_alloc(g_mlc_main->tn_header, 2);
    void *v3 = mlc_ph_find_alloc(g_mlc_main->tn_header, 3985);
    (void)v1;
    (void)v2;
    (void)v3;
    mlc_print(g_mlc_main->tn_header);
    mlc_ph_find_free(g_mlc_main->tn_header, v2);
    mlc_print(g_mlc_main->tn_header);
    mlc_ph_find_free(g_mlc_main->tn_header, v3);
    mlc_print(g_mlc_main->tn_header);
    return (g_mlc_main);
}

t_mlc_main   * g_mlc_main = NULL;
