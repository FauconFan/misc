
#include "atpt.h"

static void		updateTime(char *file, time_t *tptr)
{
	struct stat		sstat;

	if (lstat(file, &sstat) < 0)
	{
		if (errno == ENOENT)
		{
			usleep(MICRO_REFRESH_TIME);
			if (lstat(file, &sstat) < 0)
				exit(1);
		}
		else
			exit(1);
	}
	*tptr = sstat.st_mtime;
}

static void		core_child(char *file, char *cmd)
{
	char		*argv[] = {"/bin/sh", "-c", NULL, NULL};
	char		tmp[2049];
	char		*tet;

	tet = replace_in_string(cmd, '#', file);
	strncpy(tmp, tet, 2048);
	free(tet);
	argv[2] = tmp;
	execv(argv[0], argv);
	exit(1);
}

static int		core(char *file, char *cmd)
{
	time_t		t1 = 0;
	time_t		t2 = 0;
	int			status;
	pid_t		pid;

	if (atpt_init())
		return (1);
	init_signal_handlers();
	while (1)
	{
		updateTime(file, &t2);
		if (t1 != t2)
		{
			t1 = t2;
			tputs(tgetstr("cl", NULL), 1, putchar);
			printf("\n");
			if ((pid = fork()) < 0)
				exit(1);
			if (pid == 0)
				core_child(file, cmd);
			else
				waitpid(pid, &status, 0);
		}
		usleep(MICRO_REFRESH_TIME);
	}
	atpt_end();
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	return (core(argv[1], argv[2]));
}
