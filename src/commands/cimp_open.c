#include "cimp.h"

int cimp_open(t_cmd * cmd) {
	if (g_cimp->screen == NULL) {
		g_cimp->screen = cimp_init_screen(cmd->name_file);
		save_surface_jpeg("test.jpeg", g_cimp->screen->buff_screen);
		return (g_cimp->screen == NULL);
	}
	return 0;
}
