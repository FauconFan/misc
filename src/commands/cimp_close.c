#include "cimp.h"

int cimp_close(t_cmd * cmd) {
	(void) cmd;
	if (g_cimp->screen) {
		cimp_end_screen(g_cimp->screen);
		g_cimp->screen = NULL;
	}
	return 0;
}
