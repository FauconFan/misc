#ifndef MY_HEADER_H
#define	MY_HEADER_H

#include "irc_udp.h"

// my_time
void                print_time_val(struct timeval t, int fd);
struct timeval      add(struct timeval * t1, struct timeval * t2);
struct timeval      diff(struct timeval * t1, struct timeval * t2);
// fonction qui renvoie une struct timeval egale à maintenant+ 2^n secondes
struct timeval      raise(uint8_t n);

struct timeval * min_time(struct timeval t1, struct timeval t2);

void                time_assign(struct timeval * t1, struct timeval * t2);

// my_getrandom
uint64_t        gen_id();
uint32_t        gen_nonce();

// my_str
char * strnew(size_t size);
char * strjoin(const char * s1, const char * s2);
char ** strtab_strsplit(char const * s, char c);

#endif // ifndef MY_HEADER_H
