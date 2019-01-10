#include "atpt.h"

static void		signal_handler(int signo)
{
	if (signo == SIGINT ||
		signo == SIGQUIT)
	{
		atpt_end();
		exit(EXIT_SUCCESS);
	}
}

void			init_signal_handlers(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}
