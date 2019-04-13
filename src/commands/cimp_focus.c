#include "cimp.h"

/**Une fonction qui change le focus global du programme **/
t_rc_cmd cimp_focus(t_cmd * cmd) {
	g_cimp->focus = cmd->focus;
	return (OK);
}
