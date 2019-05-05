#include "irc_udp.h"

void    core_loop() {
	t_bool running = TRUE;

	env_print(g_env, ui_getfd_log());
	while (running) {
		update_buffer();
		clear_buffer();
		env_print(g_env, ui_getfd_log());
		running = select_treat_input();
	}
} /* client */
