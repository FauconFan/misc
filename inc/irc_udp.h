
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

#include "typedefs.h"

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

void    parse_datagram(uint8_t *tlv, size_t len);

uint64_t gen_id();

extern uint64_t     g_id;
// my_time.c
struct timeval      add(struct timeval *t1, struct timeval *t2);
struct timeval      raise(uint8_t n);

#endif
