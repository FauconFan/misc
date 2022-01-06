#include "irc_udp.h"

void    core_loop() {
	t_bool running = TRUE;

	send_multicast();
	env_print(g_env, ui_getfd_log());
	dprintf(ui_getfd_log(), "================================== LOOPING ==========================\n");
	while (running) {
		dprintf(ui_getfd_log(), "================================== BEGIN LOOP =======================\n");
		update_buffer(); // phase 1
		clear_buffer();  // phase 2
		g_env->need_neighbours = (lst_size(g_env->li_neighbours) < NB_NEI_MAX);
		env_print(g_env, ui_getfd_log());
		running = select_treat_input(); // phase 0
	}
} /* client */
