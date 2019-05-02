#include "irc_udp.h"

void    client() {
	t_bool running = TRUE;

	env_print(g_env, ui_getfd());
	while (running) {
		update_buffer();
		clear_buffer();
		env_print(g_env, ui_getfd());
		running = select_treat_input();
	}
} /* client */
