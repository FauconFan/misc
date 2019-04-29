#include "irc_udp.h"

t_iovec_builder     *iovb_alloc(void) {
    t_iovec_builder   *msg;
    size_t              len_tab;

    if ((msg = (t_iovec_builder *)malloc(sizeof(t_iovec_builder))) == NULL)
        return (NULL);

    len_tab = IOVEC_DEFAULT_SIZE * sizeof(struct iovec);
    if ((msg->msg_iov = malloc(len_tab)) == NULL) {
        free(msg);
        return (NULL);
    }

    memset(msg->msg_iov, 0, len_tab);

    msg->len_used = 0;
    msg->len_max = IOVEC_DEFAULT_SIZE;
    return (msg);
}

static t_bool       iovb_extend(t_iovec_builder * msg) {
    void    *v;
    size_t  len_tab;

    if (msg == NULL)
        return (FALSE);

    len_tab = msg->len_max * sizeof(struct iovec);
    if ((v = malloc(2 * len_tab)) == NULL)
        return (FALSE);
    memcpy(v, msg->msg_iov, len_tab);
    memset(v + len_tab, 0, len_tab);
    free(msg->msg_iov);
    msg->msg_iov = v;
    msg->len_max *= 2;
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

void                iovb_free(t_iovec_builder *msg) {
    if (msg == NULL)
        return ;
    for (size_t i = 0; i < msg->len_max; ++i) {
        if (msg->msg_iov[i].iov_base != NULL)
            free(msg->msg_iov[i].iov_base);
    }
    free(msg->msg_iov);
    free(msg);
}

t_bool              iovb_push(t_iovec_builder *msg, const void *v, size_t l) {
    if (msg == NULL || v == NULL)
        return (FALSE);
    while (1) {
        if (iovb_extend_if_necessary(msg) == FALSE)
            return (FALSE);
        if (msg->msg_iov[msg->len_used].iov_base == NULL)
            break ;
        msg->len_used++;
    }
    if ((msg->msg_iov[msg->len_used].iov_base = malloc(l)) == NULL) {
        return (FALSE);
    }
    memcpy(msg->msg_iov[msg->len_used].iov_base, v, l);
    msg->msg_iov[msg->len_used].iov_len = l;

    msg->len_used++;
    return (TRUE);
}

t_bool              iovb_set(t_iovec_builder *msg, size_t rk, const void * v, size_t l) {
    if (msg == NULL || v == NULL)
        return (FALSE);
    while (rk >= msg->len_max)
        iovb_extend(msg);
    if (msg->msg_iov[rk].iov_base != NULL)
        return (FALSE);
    if ((msg->msg_iov[rk].iov_base = malloc(l)) == NULL) {
        return (FALSE);
    }
    memcpy(msg->msg_iov[rk].iov_base, v, l);
    msg->msg_iov[rk].iov_len = l;
    return (TRUE);
}

t_bool              iovb_skip(t_iovec_builder *msg) {
    if (msg == NULL)
        return (FALSE);
    if (iovb_extend_if_necessary(msg) == FALSE)
        return (FALSE);
    msg->len_used++;
    return (TRUE);
}

size_t              iovb_get_index(t_iovec_builder *msg) {
    if (msg == NULL)
        return (-1);
    return (msg->len_used);
}

void                iovb_print(t_iovec_builder *msg, int fd) {
    dprintf(fd, "{ msg printing\n");
    dprintf(fd, "\tlen_used %lu\n", msg->len_used);
    dprintf(fd, "\tlen_max %lu\n", msg->len_max);
    for (size_t i = 0; i < msg->len_max; ++i) {
        dprintf(fd, "\t[%lu] -> len : %lu\n", i, msg->msg_iov[i].iov_len);
        dprintf(fd, "\t         ");

        uint8_t        *vp = (uint8_t *)msg->msg_iov[i].iov_base;

        for (size_t j = 0; j < msg->msg_iov[i].iov_len; ++j) {
            dprintf(fd, "%.2d ", vp[j]);
        }
        if (msg->msg_iov[i].iov_base == NULL) {
            dprintf(fd, "(NULL)");
        }
        dprintf(fd, "\n");
    }
    dprintf(fd, "}\n");
}

t_bool              iovb_get_iovec(t_iovec_builder *msg, struct iovec ** iovec, size_t *iovec_len) {
    if (msg == NULL || iovec == NULL || iovec_len == NULL)
        return (FALSE);
    for (size_t i = 0; i < msg->len_used; ++i) {
        if (msg->msg_iov[i].iov_len == 0) {
            return (FALSE);
        }
    }
    *iovec = msg->msg_iov;
    *iovec_len = msg->len_used;
    return (FALSE);
}
