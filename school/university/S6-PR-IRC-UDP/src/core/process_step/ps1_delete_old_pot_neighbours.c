#include "irc_udp.h"

void     ps1_delete_old_pot_neighbours(void) {
	dprintf(ui_getfd_log(), "Step 1 - Delete Old Pot Neighbours\n");
	lst_removeall_if(g_env->li_potential_neighbours, (t_bool(*)(void *))pot_nei_is_old);
}
