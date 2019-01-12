
#include "atpt.h"

static void		usage(char *argv0)
{
	printf("%s [FILE] [CMD]\n\n", argv0);
	printf("atpt will run the command CMD at any change of FILE\n");
}

int				main(int argc, char **argv)
{
	if (argc != 3)
	{
		usage((argc > 0) ? argv[0] : "");
		return (1);
	}
	if (isFileExists(argv[1]) == FALSE)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
	if (atpt_init(argv[1], argv[2]))
		return (1);
	init_signal_handlers();
	core();
	atpt_end();
	return (0);
}
