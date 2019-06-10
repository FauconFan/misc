#include "ft_malloc.h"

void show_alloc_mem(void) {
    t_mlc_main  *env;

    env = mlc_main_get();
    if (env == NULL)
        ft_put_str_ln("No env");
    else
        mlc_main_print(env);
}