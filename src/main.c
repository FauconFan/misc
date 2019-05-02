#include "irc_udp.h"

t_env * g_env = NULL;

int main(void) {
	ui_setup();

	g_env = env_alloc();
	if (g_env == NULL)
		return (1);

	env_print(g_env, ui_getfd());

	// client();
	sleep(1);

	env_free(g_env);

	ui_down();
	return (0);
}
