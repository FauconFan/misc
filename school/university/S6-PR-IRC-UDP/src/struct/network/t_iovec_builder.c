#include "irc_udp.h"

t_iovec_builder * iovb_alloc(void) {
	t_iovec_builder * msg;
	size_t len_tab;

	if ((msg = (t_iovec_builder *) malloc(sizeof(t_iovec_builder))) == NULL)
		return (NULL);

	len_tab = IOVEC_DEFAULT_SIZE * sizeof(struct iovec);
	if ((msg->msg_iov = malloc(len_tab)) == NULL) {
		free(msg);
		return (NULL);
	}

	memset(msg->msg_iov, 0, len_tab);

	msg->len_used = 0;
	msg->len_max  = IOVEC_DEFAULT_SIZE;
	return (msg);
}

static t_bool       iovb_extend(t_iovec_builder * msg) {
	void * v;
	size_t len_tab;
	static const size_t increase_size = sizeof(struct iovec) * IOVEC_EXTEND_ADD;

	if (msg == NULL)
		return (FALSE);

	len_tab = msg->len_max * sizeof(struct iovec);
	if ((v = malloc(increase_size + len_tab)) == NULL)
		return (FALSE);

	memcpy(v, msg->msg_iov, len_tab);
	memset(v + len_tab, 0, increase_size);
	free(msg->msg_iov);
	msg->msg_iov  = v;
	msg->len_max += IOVEC_EXTEND_ADD;
	return (TRUE);
}

static t_bool       iovb_extend_if_necessary(t_iovec_builder * msg) {
	if (msg == NULL)
		return (FALSE);

	if (msg->len_used == msg->len_max) {
		iovb_extend(msg);
	}
	return (TRUE);
}

void                iovb_free(t_iovec_builder * msg) {
	if (msg == NULL)
		return;

	for (size_t i = 0; i < msg->len_used; ++i) {
		free(msg->msg_iov[i].iov_base);
	}
	free(msg->msg_iov);
	free(msg);
}

t_bool              iovb_push(t_iovec_builder * msg, const void * v, size_t l) {
	if (msg == NULL || v == NULL)
		return (FALSE);

	if (iovb_extend_if_necessary(msg) == FALSE)
		return (FALSE);

	if ((msg->msg_iov[msg->len_used].iov_base = malloc(l)) == NULL) {
		return (FALSE);
	}
	memcpy(msg->msg_iov[msg->len_used].iov_base, v, l);
	msg->msg_iov[msg->len_used].iov_len = l;

	msg->len_used++;
	return (TRUE);
}

static void         swap(struct iovec * vec, size_t a, size_t b) {
	void * btmp;
	size_t ltmp;

	btmp = vec[a].iov_base;
	ltmp = vec[a].iov_len;
	vec[a].iov_base = vec[b].iov_base;
	vec[a].iov_len  = vec[b].iov_len;
	vec[b].iov_base = btmp;
	vec[b].iov_len  = ltmp;
}

static void         rearrange_recu(struct iovec * vec, size_t * iactu, size_t mtu_remain, size_t bound_max) {
	size_t imax;
	size_t lmax;
	t_bool found;

	if (*iactu >= bound_max)
		return;

	found = FALSE;
	for (size_t i = *iactu; i < bound_max; ++i) {
		if (vec[i].iov_len < mtu_remain && (found == FALSE || vec[i].iov_len > lmax)) {
			found = TRUE;
			lmax  = vec[i].iov_len;
			imax  = i;
		}
	}
	if (found == FALSE)
		return;

	swap(vec, *iactu, imax);
	*iactu = *iactu + 1;
	rearrange_recu(vec, iactu, mtu_remain - vec[*iactu - 1].iov_len, bound_max);
}

size_t              iovb_rearrange(t_iovec_builder * msg, size_t mtu) {
	size_t res;
	size_t i;
	size_t oldi;

	res = 0;
	i   = 0;
	while (i < msg->len_used) {
		oldi = i;
		rearrange_recu(msg->msg_iov, &i, mtu, msg->len_used);
		if (oldi == i)
			return (0);

		res++;
	}
	return (res);
}

void                iovb_print(t_iovec_builder * msg, int fd) {
	dprintf(fd, "{ iovb printing, len_used %lu, len_max %lu\n", msg->len_used, msg->len_max);
	for (size_t i = 0; i < msg->len_max; ++i) {
		dprintf(fd, "\t[%lu], len : %lu -> ", i, msg->msg_iov[i].iov_len);

		uint8_t * vp = (uint8_t *) msg->msg_iov[i].iov_base;

		for (size_t j = 0; j < msg->msg_iov[i].iov_len; ++j) {
			dprintf(fd, "%.2d ", vp[j]);
		}
		if (msg->msg_iov[i].iov_base == NULL) {
			dprintf(fd, "(NULL)");
		}
		dprintf(fd, "\n");
	}
	dprintf(fd, "}");
}
