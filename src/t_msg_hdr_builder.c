#include "irc_udp.h"

t_msg_hdr_builder   *mhb_alloc(void) {
    t_msg_hdr_builder   *msg;
    size_t              len_tab;

    if ((msg = (t_msg_hdr_builder *)malloc(sizeof(t_msg_hdr_builder))) == NULL)
        return (NULL);
    
    len_tab = MSG_HDR_DEFAULT_SIZE * sizeof(struct iovec);
    if ((msg->msg_iov = malloc(len_tab)) == NULL) {
        free(msg);
        return (NULL);
    }

    memset(msg->msg_iov, 0, len_tab);

    msg->len_used = 0;
    msg->len_max = MSG_HDR_DEFAULT_SIZE;
    return (msg);
}

static t_bool       mbh_extend_if_necessary(t_msg_hdr_builder * msg) {
    void    *v;
    size_t  len_tab;

    if (msg->len_used == msg->len_max) {
        len_tab = msg->len_max * sizeof(struct iovec);
        if ((v = malloc(2 * len_tab)) == NULL)
            return (FALSE);
        memcpy(v, msg->msg_iov, len_tab);
        memset(v + len_tab, 0, len_tab);
        free(msg->msg_iov);
        msg->msg_iov = v;
        msg->len_max *= 2;
    }
    return (TRUE);
}

void                mbh_free(t_msg_hdr_builder *msg) {
    if (msg == NULL)
        return ;
    for (size_t i = 0; i < msg->len_used; ++i) {
        free(msg->msg_iov[i].iov_base);
    }
    free(msg->msg_iov);
    free(msg);
}

t_bool              mbh_add(t_msg_hdr_builder *msg, void *v, size_t l) {
    if (msg == NULL || v == NULL)
        return (FALSE);
    if (mbh_extend_if_necessary(msg) == FALSE)
        return (FALSE);
    if ((msg->msg_iov[msg->len_used].iov_base = malloc(l)) == NULL) {
        return (FALSE);
    }
    memcpy(msg->msg_iov[msg->len_used].iov_base, v, l);
    msg->msg_iov[msg->len_used].iov_len = l;

    msg->len_used++;
    return (TRUE);
}

void                mbh_print(t_msg_hdr_builder *msg) {
    printf("{ msg printing\n");
    printf("\tlen_used %lu\n", msg->len_used);
    printf("\tlen_max %lu\n", msg->len_max);
    for (size_t i = 0; i < msg->len_max; ++i) {
        printf("\t[%lu] -> len : %lu\n", i, msg->msg_iov[i].iov_len);
        printf("\t         ");
        
        char        *vp = (char *)msg->msg_iov[i].iov_base;

        for (size_t j = 0; j < msg->msg_iov[i].iov_len; ++j) {
            printf("%.x ", vp[j]);
        }
        if (msg->msg_iov[i].iov_base == NULL) {
            printf("(NULL)");
        }
        printf("\n");
    }
    printf("}\n");
}

void                mbh_get_iovec(t_msg_hdr_builder *msg, struct iovec ** iovec, size_t *iovec_len) {
    if (msg == NULL || iovec == NULL || iovec_len == NULL)
        return ;
    *iovec = msg->msg_iov;
    *iovec_len = msg->len_used;
}