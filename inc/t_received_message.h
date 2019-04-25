// messages reçus

// id, nonce
// type
// affiché ? --> si on l'a déja reçu pas besoin de le réafficher

#ifndef T_RECEIVED_MESSAGE_H
#define T_RECEIVED_MESSAGE_H

#include "irc_udp.h"

typedef struct      s_received_message{
    uint64_t        sender_id;
    uint32_t        nonce;
    uint8_t         type;
    uint8_t         *text;
    uint8_t         length;
}                   t_received_message;

t_received_message      *message_alloc(uint64_t id, uint32_t nonce, uint8_t type, uint8_t length, uint8_t *text);
void                    message_free(t_received_message *message);

// une fonction pour afficher le message
void                    print_message(t_received_message *message);


// prédicat d'égalité
t_bool                  is_message(t_received_message *message, uint64_t id, uint32_t nonce);





#endif
