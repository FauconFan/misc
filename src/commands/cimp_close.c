#include "cimp.h"

t_rc_cmd cimp_close(t_cmd * cmd) {
	(void) cmd;
	cimp_screen_end(g_cimp->screen[cmd->focus]);
	g_cimp->screen[cmd->focus] = NULL;
	if(g_cimp->focus == cmd->focus){
		g_cimp->focus = get_next_focus(g_cimp->focus);
	}
	return OK;
}
