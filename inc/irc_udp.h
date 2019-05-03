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

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "typedefs.h"
#include "ui.h"
#include "utils.h"

#define	JCH_NODE         "jch.irif.fr"
#define	JCH_SERVICE      "1212"

#define	ENV_FAMILY       AF_INET6
#define	ENV_SOCKTYPE     SOCK_DGRAM
#define	ENV_PROTOCOL     0
#define	ENV_FLAGS        (AI_V4MAPPED | AI_ALL)

#define	NB_NEI_MAX       8
#define	TIMEOUT_POT_NEI  30
#define	TIMEOUT_NEI_TIME 30

t_bool      get_sockaddr_juliusz(
  struct sockaddr ** sock_addr,
  socklen_t *        sock_len);

t_bool      get_sockaddr(
  const char *       node,
  const char *       service,
  struct sockaddr ** sock_addr,
  socklen_t *        sock_len);

void    core_loop();

int     build_socket(void);

void    parse_datagram(uint8_t * tlv, size_t len, t_neighbour * nei, t_ip_port ip_port);

t_bool  select_treat_input(void);
void    update_buffer(void);
void    clear_buffer(void);

extern t_env * g_env;
extern char * g_pseudo;

#endif // ifndef IRC_UDP_H
