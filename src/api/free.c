#include "ft_malloc.h"

void free(void * ptr) {
    t_mlc_main *env;

    if (ptr == NULL)
        return ;
    env = mlc_main_get();
    if (env == NULL)
        return ;
    mlc_main_find_free(env, ptr);    
}