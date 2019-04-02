#ifndef TYPEDEFS_H
#define TYPEDEFS_H

// Globals defines

#define TRUE        1
#define FALSE       0

typedef uint8_t     t_bool;

// Project defines

#define MAGIC_NUMBER    93
#define VERSION         2

typedef enum    e_tlv_type {
    PAD1 = 0,
    PADN,
}               t_tlv_type;

// Struct declarations

#include "t_iovec_builder.h"
#include "t_tlv_builder.h"

#endif