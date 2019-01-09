#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <term.h>
#include <curses.h>
#include <string.h>

#define	FI	"/tmp/oui/tp.py"
#define PY	"/usr/bin/python3"

void	updateTime(char *file, time_t *tptr);
void	exec();

int	main(void)
{
	time_t		ti = 0;
	time_t		ti2 = 0;

	if (tgetent(NULL, getenv("TERM")) < 0)
		exit(1);
	updateTime(FI, &ti);
	while (1)
	{
		updateTime(FI, &ti2);
		if (ti2 != ti)
		{
			ti = ti2;
			exec();
		}
		usleep(100);
	}
	return (0);
}

void	updateTime(char *file, time_t *tptr)
{
	struct stat	sstat;

	if (lstat(file, &sstat) < 0)
		exit(1);
	*tptr = sstat.st_mtime;
}

void	exec()
{
	char			*argv[] = {PY, FI, NULL};
	struct winsize	ws;
	char			*pad;
	int				status;
	int				pid;
	int				column_count;
	int				line_count;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &ws);
	column_count = ws.ws_col;
	line_count = ws.ws_row;
	if ((pad = (char *)malloc(sizeof(char) * (column_count + 1))) == NULL)
		exit(1);
	pad[column_count] = '\0';
	memset(pad, '=', column_count);
	tputs(tgetstr("cl", NULL), 1, putchar);
	printf("\n%s\n%s\n\n", pad, pad);
	memset(pad, '-', column_count);
	printf("%s\n", pad);
	if ((pid = fork()) < 0)
		exit(1);
	if (pid == 0)
	{
		execv(PY, argv);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	free(pad);
}
