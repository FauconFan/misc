#ifndef MY_HEADER_H
#define	MY_HEADER_H

#include "irc_udp.h"

// my_time
void                timeval_print(struct timeval t, int fd);
void                timeval_add(struct timeval * res, struct timeval t1, struct timeval t2);
void                timeval_diff(struct timeval * res, struct timeval t1, struct timeval t2);
void                timeval_raise(struct timeval * res, uint8_t n);
struct timeval * timeval_min(struct timeval * t1, struct timeval * t2);
t_bool              timeval_lessthan(struct timeval t1, struct timeval t2);
void                timeval_assign(struct timeval * t1, struct timeval t2);

// my_getrandom
uint64_t        gen_id();
uint32_t        gen_nonce();
float           gen_rand();
int             gen_randint(int max);

// my_str
char * strnew(size_t size);
char * strjoin(const char * s1, const char * s2);
void strreplace(char ** str, char * pattern, char * with);

#endif // ifndef MY_HEADER_H
