#include "cimp.h"

int cimp_open(t_cmd * cmd) {
	if (g_cimp->screen == NULL) {
		g_cimp->screen = cimp_screen_init(cmd->name);
		return (g_cimp->screen == NULL);
	}
	return 0;
}
