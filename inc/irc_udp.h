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
#include <ifaddrs.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "typedefs.h"
#include "core.h"
#include "ui.h"
#include "utils.h"
#include "struct/env_utils.h"

#define	JCH_NODE              "jch.irif.fr"
#define	JCH_SERVICE           "1212"

#define	MULTICAST_ADDR        "ff12:b456:dad4:cee1:4589:71de:a2ec:0e66"
#define	MULTICAST_PORT        1212

#define	ENV_FAMILY            AF_INET6
#define	ENV_SOCKTYPE          SOCK_DGRAM
#define	ENV_PROTOCOL          0
#define	ENV_FLAGS             (AI_V4MAPPED | AI_ALL)

#define	DEFAULT_PORT          4242
#define	NO_PORT               -1
#define	GMTU                  1024
#define	NB_NEI_MAX            8
#define	TIMEOUT_POT_NEI       30
#define	TIMEOUT_NEI_TIME      30
#define	TIMEOUT_CHECK_MSG     120
#define	TIMEOUT_POT_NEI_RETRY 5
#define	PERCENT_SEND_NEI      0.30 // 30%

#define	SIZE_PSEUDO           20
#define	WITH_NCURSES_DEFAULT  TRUE
#define	WITH_LOG_DEFAULT      FALSE
#define	WITH_JULIUSZ_INIT     TRUE

#define	NO_HELLO              "No hello received for too long"
#define	NO_ACK                "No ack in time"
#define	GOOD_BYE              "Au revoir"

extern t_env * g_env;
extern char g_pseudo[SIZE_PSEUDO + 1];

#endif // ifndef IRC_UDP_H
