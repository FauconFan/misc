#include "cimp.h"

t_rc_cmd cimp_open(t_cmd * cmd) {
	int rc = get_available_id();

	if (rc != -1 && cmd != NULL) {
		g_cimp->screen[rc] = cimp_screen_init(cmd->name);
		if (g_cimp->screen[rc] == NULL)
			return (ABORT);

		g_cimp->focus = rc;
		return (OK);
	}
	return (FAIL);
}
