#ifndef TYPEDEFS_H
#define TYPEDEFS_H

// Globals defines

#define TRUE        1
#define FALSE       0

typedef uint8_t     t_bool;

// Project defines

#define MAGIC_NUMBER    93
#define VERSION         2

#define RANGE_MIN_TLV_TYPE  0
#define RANGE_MAX_TLV_TYPE  7

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

#include "t_list.h"
#include "t_iovec_builder.h"
#include "t_tlv_builder.h"
#include "my_header.h"
#include "t_acquit_message.h"
#include "t_neighbour.h"
#include "t_potential_neighbour.h"
#include "t_received_message.h"

#endif
