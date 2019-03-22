#include "cimp.h"

int cimp_open(t_cmd * cmd) {
	if (g_cimp->screen == NULL) {
		g_cimp->screen = cimp_init_screen(cmd->name);
		return (g_cimp->screen == NULL);
	}
	return 0;
}
