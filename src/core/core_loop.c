#include "irc_udp.h"

void    core_loop() {
	t_bool running = TRUE;

	env_print(g_env, ui_getfd());
	while (running) {
		update_buffer();
		clear_buffer();
		dprintf(ui_getfd(), "\n");
		env_print(g_env, ui_getfd());
		running = select_treat_input();
	}
} /* client */
