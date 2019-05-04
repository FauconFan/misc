#include "irc_udp.h"

static void    build_name(char name[4096]) {
	time_t traw;
	struct tm * info;

	memset(name, 0, 4096);
	time(&traw);
	info = localtime(&traw);
	snprintf(name, 4095, ".logs/%d_%02d_%02d__%02d:%02d:%02d.log", 1900 + info->tm_year, 1 + info->tm_mon, info->tm_mday,
	  info->tm_hour, info->tm_min, info->tm_sec);
}

static t_bool   log_dir_setup(void) {
	struct stat statbuff;
	char * error_stat;
	char * error_mkdir;

	if (stat(".logs", &statbuff) == 0) {
		if (S_ISDIR(statbuff.st_mode) == 0) {
			printf("LOGGER FAILS : .logs exists and is not a folder\n");
			return (FALSE);
		}
	}
	else {
		error_stat = strerror(errno);
		if (mkdir(".logs", 0755) == -1) {
			error_mkdir = strerror(errno);
			printf("LOGGER FAILS : fail to create .logs file\n");
			printf("stat error : %s\n", error_stat);
			printf("mkdir error : %s\n", error_mkdir);
			return (FALSE);
		}
	}
	return (TRUE);
}

t_bool  ui_log_setup(int * fd) {
	char name[4096];

	if (log_dir_setup() == FALSE)
		return (FALSE);

	build_name(name);
	printf("Log file: %s\n", name);
	*fd = open(name, O_WRONLY | O_CREAT, 0664);
	if (*fd == -1) {
		printf("LOGGER FAILS : fail to create log file\n");
		printf("error %s\n", strerror(errno));
		return (FALSE);
	}
	return (TRUE);
}
