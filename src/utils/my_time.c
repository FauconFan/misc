#include "irc_udp.h"

void                print_time_val(struct timeval t) {
    printf("tv { sec : %ld, ms : %ld }", t.tv_sec, t.tv_usec);
}

struct timeval      add(struct timeval *t1, struct timeval *t2){
    struct timeval time;
    time.tv_sec = t1->tv_sec + t2->tv_sec;
    time.tv_usec = t1->tv_usec + t2->tv_usec;
    return time;
}

struct timeval      diff(struct timeval *t1, struct timeval *t2){
    if (t1 != min_time(*t1, *t2))
        return diff(t2, t1);
    struct timeval time;
    time.tv_sec = t1->tv_sec - t2->tv_sec;
    time.tv_usec = t1->tv_usec -t2->tv_usec;
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

struct timeval      *min_time(struct timeval t1, struct timeval t2){
    if(t1.tv_sec == t2.tv_sec)
        return ((t1.tv_usec < t2.tv_usec)? &t1 : &t2);
    return ((t1.tv_sec < t2.tv_sec)? &t1 : &t2);
}

void                time_assign(struct timeval *t1, struct timeval *t2){
    t1->tv_sec = t2->tv_sec;
    t1->tv_usec = t2->tv_usec;
}
