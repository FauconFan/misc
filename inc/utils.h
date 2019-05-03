#ifndef MY_HEADER_H
#define	MY_HEADER_H

#include "irc_udp.h"

// my_time
void                timeval_print(struct timeval t, int fd);
struct timeval      timeval_add(struct timeval * t1, struct timeval * t2);
struct timeval      timeval_diff(struct timeval * t1, struct timeval * t2);
struct timeval      timeval_raise(uint8_t n);
struct timeval * timeval_min(struct timeval * t1, struct timeval * t2);
void                timeval_assign(struct timeval * t1, struct timeval * t2);

// my_getrandom
uint64_t        gen_id();
uint32_t        gen_nonce();

// my_str
char * strnew(size_t size);
char * strjoin(const char * s1, const char * s2);
void strreplace(char ** str, char * pattern, char * with);

#endif // ifndef MY_HEADER_H
