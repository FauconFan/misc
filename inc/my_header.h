#ifndef MY_HEADER_H
#define MY_HEADER_H

#include "irc_udp.h"

//my_time
struct timeval      add(struct timeval *t1, struct timeval *t2);
// fonction qui renvoie une struct timeval egale à maintenant+ 2^n secondes
struct timeval      raise(uint8_t n);


// my_getrandom
uint64_t 		gen_id();
uint32_t		gen_nonce();

#endif
