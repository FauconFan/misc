#include "atpt.h"

static void		core_child(void)
{
	char		*argv[] = {"/bin/sh", "-c", NULL, NULL};
	char		tmp[2049];
	char		*tet;

	tet = replace_in_string(g_atpt->cmd, '#', g_atpt->file);
	strncpy(tmp, tet, 2048);
	free(tet);
	argv[2] = tmp;
	execv(argv[0], argv);
	exit(1);
}

void			core(void)
{
	time_t		t1 = 0;
	time_t		t2 = 0;
	int			status;
	pid_t		pid;

	while (1)
	{
		t2 = getModificationDate(g_atpt->file);
		if (t1 != t2)
		{
			t1 = t2;
			tputs(tgetstr("cl", NULL), 1, putchar);
			print_header();
			if ((pid = fork()) < 0)
				exit(1);
			if (pid == 0)
				core_child();
			else
				waitpid(pid, &status, 0);
		}
		usleep(MICRO_REFRESH_TIME);
	}
}
