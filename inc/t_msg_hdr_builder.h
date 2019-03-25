#ifndef T_MSG_HDR_BUILDER_H
#define T_MSG_HDR_BUILDER_H

#define MSG_HDR_DEFAULT_SIZE     8

typedef struct      s_msg_hdr_builder {
    struct iovec    *msg_iov;
    size_t          len_used;
    size_t          len_max;
}                   t_msg_hdr_builder;

t_msg_hdr_builder   *mhb_alloc(void);
void                mbh_free(t_msg_hdr_builder *msg);
t_bool              mbh_add(t_msg_hdr_builder *msg, void *v, size_t l);
void                mbh_print(t_msg_hdr_builder *msg);
void                mbh_get_iovec(t_msg_hdr_builder *msg, struct iovec ** iovec, size_t *iovec_len);

#endif