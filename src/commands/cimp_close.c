#include "cimp.h"

t_rc_cmd cimp_close(t_cmd * cmd) {
	(void) cmd;
	if (g_cimp->screen[g_cimp->focus]) {
		cimp_screen_end(g_cimp->screen[g_cimp->focus]);
		g_cimp->screen[g_cimp->focus] = NULL;
	}
	g_cimp->focus = -1;
	return OK;
}
