#ifndef TYPEDEFS_H
#define	TYPEDEFS_H

// Globals defines

typedef enum    e_bool{
	FALSE = 0,
	TRUE  = 1,
}               t_bool;

#define	STR_OF_BOOL(a) ((a) ? "TRUE" : "FALSE")

// Project defines

#define	MAGIC_NUMBER 93
#define	VERSION      2

#define	FREE_PTR(ptr)  ((void(*)(void *))(ptr))
#define	PRINT_PTR(ptr) ((void(*)(void *, int))(ptr))

// Struct declarations

#include "struct/data/t_list.h"
#include "struct/network/t_ip_port.h"
#include "struct/network/t_iovec_builder.h"
#include "struct/network/t_tlv_builder.h"
#include "struct/network/t_buffer_tlv_ip.h"
#include "struct/protocol/t_acquit.h"
#include "struct/protocol/t_neighbour.h"
#include "struct/protocol/t_potential_neighbour.h"
#include "struct/protocol/t_message.h"
#include "struct/t_env.h"

#endif // ifndef TYPEDEFS_H
