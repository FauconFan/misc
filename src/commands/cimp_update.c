#include "cimp.h"

t_rc_cmd cimp_update(t_cmd * cmd) {
	if (g_cimp->screen) {
		char * name;
		int ret;

		if (cmd->name)
			name = cmd->name;
		else
			name = g_cimp->screen->path;
		ret = (cimp_screen_set_surface(g_cimp->screen, name)) == FALSE;
		if (ret == 0 && cmd->name != NULL)
			ret = (cimp_screen_set_path(g_cimp->screen, name) == FALSE);
		return (ret);
	}
	return (OK);
}
