
#include "atpt.h"


static int	core(char *file, char *cmd)
{
	(void)file;
	(void)cmd;
	if (atpt_init())
		return (1);
	init_signal_handlers();
	while (1)
	{
		tputs(tgetstr("cl", NULL), 1, putchar);
		printf("%s\n", "oui");
		sleep(1);
	}
	atpt_end();
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	return (core(argv[1], argv[2]));
}
