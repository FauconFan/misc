#include "cimp.h"


int cimp_copy(t_cmd * cmd) {
    (void) cmd;
    return 0;
}

int cimp_paste(t_cmd * cmd) {
    (void) cmd;

    if(cimp_copy < 0){
        return -1;
    }

    if(int SDL_FillRect(g_cimp->screen->buff_screen, cmd->rect, ) < 0)
                 return -1;

    return 0;
}

int cimp_cut(t_cmd * cmd) {
    (void) cmd;
    return 0;
}
