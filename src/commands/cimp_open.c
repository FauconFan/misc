#include "cimp.h"

int cimp_open(t_cmd * cmd) {
<<<<<<< HEAD
	if (g_cimp->screen == NULL && cmd != NULL) {
		g_cimp->screen = cimp_init_screen(cmd->name);
=======
	if (g_cimp->screen == NULL) {
		g_cimp->screen = cimp_screen_init(cmd->name);
>>>>>>> origin/dev
		return (g_cimp->screen == NULL);
	}
	return 0;
}
