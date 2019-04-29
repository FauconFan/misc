#ifndef TYPEDEFS_H
#define TYPEDEFS_H

// Globals defines

#define TRUE        1
#define FALSE       0

typedef uint8_t     t_bool;

// Project defines

#define MAGIC_NUMBER    93
#define VERSION         2

#define FREE_PTR(ptr)   ((void (*)(void *))(ptr))
#define PRINT_PTR(ptr)  ((void (*)(void *))(ptr))

typedef enum    e_tlv_type {
    PAD1 = 0,
    PADN = 1,
    HELLO = 2,
    NEIGHBOUR = 3,
    DATA = 4,
    ACK = 5,
    GOAWAY = 6,
    WARNING = 7,
}               t_tlv_type;

// Struct declarations

#include "utils.h"

#include "struct/t_list.h"
#include "struct/t_iovec_builder.h"
#include "struct/t_tlv_builder.h"
#include "struct/t_acquit.h"
#include "struct/t_neighbour.h"
#include "struct/t_potential_neighbour.h"
#include "struct/t_message.h"
#include "struct/t_buffer_tlv_ip.h"
#include "struct/t_env.h"

#endif
