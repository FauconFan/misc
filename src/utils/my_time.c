#include "irc_udp.h"


struct timeval      add(struct timeval *t1, struct timeval *t2){
    struct timeval time;
    time.tv_sec = t1->tv_sec + t2->tv_sec;
    time.tv_usec = t1->tv_usec + t2->tv_usec;
    return time;
}

struct timeval      raise(uint8_t n){
    struct timeval  time;
    uint32_t        sec = 2;
    for (size_t i = 0; i < n; i++) {
        sec = sec*2;
    }
    gettimeofday(&time, NULL);
    time.tv_sec = time.tv_sec + sec;
    return time;
}
