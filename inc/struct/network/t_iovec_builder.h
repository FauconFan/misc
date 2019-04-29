#ifndef T_IOVEC_BUILDER_H
#define T_IOVEC_BUILDER_H

#include "irc_udp.h"

#define IOVEC_DEFAULT_SIZE     8

/**
 *  iovec builder is a structure that helps users to build arrays of iovec.
 *  This structure is used and then iovec arrays are used for send function. 
 */
typedef struct      s_iovec_builder {
    struct iovec    *msg_iov; // iovec dynamic array
    size_t          len_used; // len actually used
    size_t          len_max; // len allocated in iovec
}                   t_iovec_builder;

// Alloc a new structure.
t_iovec_builder    *iovb_alloc(void);

// Free the structure.
void                iovb_free(t_iovec_builder *msg);

// Push the value v with len l to the iovec builder msg.
t_bool              iovb_push(t_iovec_builder *msg, const void *v, size_t l);

// Set the rk iovec in the array to value v with len l in the iovec builder msg.
t_bool              iovb_set(t_iovec_builder *msg, size_t rk, const void *v, size_t l);

// Skip the actual rank in the iovec builder msg.
t_bool              iovb_skip(t_iovec_builder *msg);

// Return the actual rank in the iovec builder msg.
size_t              iovb_get_index(t_iovec_builder *msg);

// Print a human readable form of the iovec builder msg.
void                iovb_print(t_iovec_builder *msg, int fd);

// Return a array of iovec in the parameters.
// Return true if it's all good.
// Return false if there is skipped case unfilled.
t_bool              iovb_get_iovec(t_iovec_builder *msg, struct iovec ** iovec, size_t *iovec_len);

#endif