#include "atpt.h"

time_t		getModificationDate(char *file)
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
	return (sstat.st_mtime);
}

t_bool		isFileExists(char *file)
{
	struct stat		sstat;

	if (lstat(file, &sstat) < 0)
	{
		return (FALSE);
	}
	return (TRUE);
}
