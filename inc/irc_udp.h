
#ifndef IRC_UDP_H
#define IRC_UDP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <sys/time.h>
#include <sys/select.h>
#include <fcntl.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE        1
#define FALSE       0

typedef uint8_t     t_bool;

#include "t_iovec_builder.h"
#include "t_tlv.h"

void    getSocketJuliusz(
                const char * node,
                const char * service,
                int * sfd,
                struct sockaddr ** sock_addr,
                socklen_t * sock_len);

void    client(
                int sfd,
                struct sockaddr *sock_addr,
                socklen_t sock_len,
                const void * buff,
                size_t len_buff,
                void *buff2,
                size_t len_buff2);

uint64_t gen_id();

extern uint64_t     g_id;

#endif
