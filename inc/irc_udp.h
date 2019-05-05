#ifndef IRC_UDP_H
#define	IRC_UDP_H

#define	_GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <ctype.h>
#include <math.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "typedefs.h"
#include "core.h"
#include "ui.h"
#include "utils.h"

#define	JCH_NODE             "jch.irif.fr"
#define	JCH_SERVICE          "1212"

#define	ENV_FAMILY           AF_INET6
#define	ENV_SOCKTYPE         SOCK_DGRAM
#define	ENV_PROTOCOL         0
#define	ENV_FLAGS            (AI_V4MAPPED | AI_ALL)

#define	NB_NEI_MAX           8
#define	TIMEOUT_POT_NEI      30
#define	TIMEOUT_NEI_TIME     30

#define	SIZE_PSEUDO          20
#define	WITH_NCURSES_DEFAULT TRUE
#define	WITH_LOG_DEFAULT     FALSE

t_bool    parse_args(int argc, char ** argv, t_bool * with_ncurses, t_bool * with_log);

extern t_env * g_env;
extern char g_pseudo[SIZE_PSEUDO + 1];

#endif // ifndef IRC_UDP_H
