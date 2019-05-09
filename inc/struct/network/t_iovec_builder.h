#ifndef T_IOVEC_BUILDER_H
#define	T_IOVEC_BUILDER_H

#include "irc_udp.h"

#define	IOVEC_DEFAULT_SIZE 8
#define	IOVEC_EXTEND_ADD   2

/**
 *  iovec builder is a structure that helps users to build arrays of iovec.
 *  This structure is used and then iovec arrays are used for send function.
 */
typedef struct      s_iovec_builder{
	struct iovec * msg_iov;  // iovec dynamic array
	size_t         len_used; // len actually used
	size_t         len_max;  // len allocated in iovec
}                   t_iovec_builder;

// Alloc a new structure.
t_iovec_builder * iovb_alloc(void);

// Free the structure.
void                iovb_free(t_iovec_builder * msg);

// Push the value v with len l to the iovec builder msg.
t_bool              iovb_push(t_iovec_builder * msg, const void * v, size_t l);

// Rearrange elements in the buffer to allow messages packing less than mtu.
// Returns the number of iovec need for this mtu.
// Return 0 if errors or if there is a message longer that mtu.
size_t              iovb_rearrange(t_iovec_builder * msg, size_t mtu);

// Print a human readable form of the iovec builder msg.
void                iovb_print(t_iovec_builder * msg, int fd);

#endif // ifndef T_IOVEC_BUILDER_H
