#include "cimp.h"

t_rc_cmd cimp_open(t_cmd * cmd) {
	if (g_cimp->screen == NULL && cmd != NULL) {
		g_cimp->screen = cimp_screen_init(cmd->name);
		if (g_cimp->screen == NULL)
			return (ABORT);
		return (OK);
	}
	return (FAIL);
}
