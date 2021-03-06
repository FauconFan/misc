#include "irc_udp.h"

static int      fill_buffer(int fd, uint8_t * buffer, size_t len) {
	size_t len_read;
	int ret_read;

	len_read = 0;
	while (len_read < len) {
		if ((ret_read = read(fd, buffer + len_read, len - len_read)) < 0)
			return (1);

		len_read += ret_read;
	}
	return (0);
}

static int      my_getrandom(void * buffer, size_t len) {
	int fd_random;
	int ret;

	ret = 0;
	if ((fd_random = open("/dev/urandom", O_RDONLY)) < 0)
		return (1);

	if (fill_buffer(fd_random, (uint8_t *) buffer, len))
		ret = 2;
	if (close(fd_random))
		ret = 1;
	return (ret);
}

uint64_t        gen_id() {
	uint64_t id;

	if (my_getrandom(&id, 8) != 0) {
		dprintf(ui_getfd_log(), "Erreur de génération id : %s\n", strerror(errno));
		return 0;
	}
	return id;
}

uint32_t        gen_nonce() {
	uint32_t nonce;

	if (my_getrandom(&nonce, 4) != 0) {
		dprintf(ui_getfd_log(), "Erreur de génération nonce : %s\n", strerror(errno));
		return 0;
	}
	return nonce;
}

float           gen_rand() {
	uint64_t rnd;
	float res;

	rnd = 0;
	if (my_getrandom(&rnd, sizeof(rnd)) != 0) {
		dprintf(ui_getfd_log(), "Erreur de génération nonce : %s\n", strerror(errno));
		return 0;
	}
	rnd = rnd >> 8;
	res = (float) rnd / (float) ((uint64_t) (1) << (8 * (sizeof(rnd) - 1)));
	return (res);
}

int             gen_randint(int max) {
	int res;
	float tmp;

	if (max < 0)
		return (0);

	tmp = gen_rand();
	res = (int) (tmp * max);
	// impossible, but still bound result
	if (res < 0)
		res = 0;
	else if (res >= max)
		res = max - 1;
	return (res);
}
