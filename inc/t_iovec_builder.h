#ifndef T_IOVEC_BUILDER_H
#define T_IOVEC_BUILDER_H

#include "irc_udp.h"

#define IOVEC_DEFAULT_SIZE     8

typedef struct      s_iovec_builder {
    struct iovec    *msg_iov;
    size_t          len_used;
    size_t          len_max;
}                   t_iovec_builder;

t_iovec_builder    *iovb_alloc(void);
void                iovb_free(t_iovec_builder *msg);
t_bool              iovb_push(t_iovec_builder *msg, const void *v, size_t l);
t_bool              iovb_set(t_iovec_builder *msg, size_t rk, const void *v, size_t l);
t_bool              iovb_skip(t_iovec_builder *msg);
size_t              iovb_get_index(t_iovec_builder *msg);
void                iovb_print(t_iovec_builder *msg);
t_bool              iovb_get_iovec(t_iovec_builder *msg, struct iovec ** iovec, size_t *iovec_len);

#endif