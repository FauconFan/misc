#include "irc_udp.h"

void                timeval_print(struct timeval t, int fd) {
	dprintf(fd, "tv { sec : %ld, ms : %ld }", t.tv_sec, t.tv_usec);
}

void                timeval_add(struct timeval * res, struct timeval t1, struct timeval t2) {
	res->tv_sec = t1.tv_sec + t2.tv_sec;
	if (t1.tv_usec + t2.tv_usec >= 1e6) {
		res->tv_usec = (t1.tv_usec + t2.tv_usec) % 1000000;
		res->tv_sec += 1;
	}
	else {
		res->tv_usec = t1.tv_usec + t2.tv_usec;
	}
}

void                timeval_diff(struct timeval * res, struct timeval t1, struct timeval t2) {
	if (timeval_lessthan(t2, t1))
		return (timeval_diff(res, t2, t1));

	if (t1.tv_usec < t2.tv_usec) {
		res->tv_sec  = t2.tv_sec - t1.tv_sec;
		res->tv_usec = t2.tv_usec - t1.tv_usec;
	}
	else {
		res->tv_sec  = t2.tv_sec - t1.tv_sec - 1;
		res->tv_usec = 1e6 - (t1.tv_usec - t2.tv_usec); // ms
	}
}

void                timeval_raise(struct timeval * res, uint8_t n) {
	uint32_t sec = 1;

	if (n > 0) {
		for (size_t i = 0; i < (size_t) (n - 1); i++) {
			sec = sec * 2;
		}
	}
	struct timeval plus_time;
	plus_time.tv_sec  = sec + gen_randint(sec);
	plus_time.tv_usec = gen_randint(1e6);

	timeval_add(res, g_env->now, plus_time);
}

struct timeval * timeval_min(struct timeval * t1, struct timeval * t2) {
	if (t1->tv_sec == t2->tv_sec)
		return ((t1->tv_usec < t2->tv_usec) ? t1 : t2);

	return ((t1->tv_sec < t2->tv_sec) ? t1 : t2);
}

t_bool              timeval_lessthan(struct timeval t1, struct timeval t2) {
	return ((t1.tv_sec < t2.tv_sec) || (t1.tv_sec == t2.tv_sec && t1.tv_usec < t2.tv_usec));
}

void                timeval_assign(struct timeval * t1, struct timeval t2) {
	t1->tv_sec  = t2.tv_sec;
	t1->tv_usec = t2.tv_usec;
}
