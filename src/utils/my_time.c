#include "irc_udp.h"

void                timeval_print(struct timeval t, int fd) {
	dprintf(fd, "tv { sec : %ld, ms : %ld }", t.tv_sec, t.tv_usec);
}

struct timeval      timeval_add(struct timeval * t1, struct timeval * t2) {
	struct timeval time;

	time.tv_sec  = t1->tv_sec + t2->tv_sec;
	time.tv_usec = t1->tv_usec + t2->tv_usec;
	return time;
}

struct timeval      timeval_diff(struct timeval * t1, struct timeval * t2) {
	if (t1 != timeval_min(t1, t2))
		return (timeval_diff(t2, t1));

	struct timeval time;

	if (t1->tv_usec < t2->tv_usec) {
		time.tv_sec  = t2->tv_sec - t1->tv_sec;
		time.tv_usec = t2->tv_usec - t1->tv_usec;
	}
	else {
		time.tv_sec  = t2->tv_sec - t1->tv_sec - 1;
		time.tv_usec = 1e6 - (t1->tv_usec - t2->tv_usec);
	}

	return (time);
}

struct timeval      timeval_raise(uint8_t n) {
	struct timeval time;
	uint32_t sec = 2;

	for (size_t i = 0; i < n; i++) {
		sec = sec * 2;
	}
	gettimeofday(&time, NULL);
	time.tv_sec = time.tv_sec + sec;
	return time;
}

struct timeval * timeval_min(struct timeval * t1, struct timeval * t2) {
	if (t1->tv_sec == t2->tv_sec)
		return ((t1->tv_usec < t2->tv_usec) ? t1 : t2);

	return ((t1->tv_sec < t2->tv_sec) ? t1 : t2);
}

void                timeval_assign(struct timeval * t1, struct timeval * t2) {
	t1->tv_sec  = t2->tv_sec;
	t1->tv_usec = t2->tv_usec;
}
