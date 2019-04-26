// messages reçus

// id, nonce
// type
// affiché ? --> si on l'a déja reçu pas besoin de le réafficher

#ifndef T_MESSAGE_H
#define T_MESSAGE_H

#include "irc_udp.h"

typedef struct      s_message{
    uint64_t        sender_id;
    uint32_t        nonce;
    uint8_t         type;
    uint8_t         length;
    uint8_t         *text;
}                   t_message;

t_message               *message_alloc(uint64_t id, uint32_t nonce, uint8_t type, uint8_t length, uint8_t *text);
void                    message_free(t_message *message);

// une fonction pour afficher le message
void                    message_print(t_message *message);


// prédicat d'égalité
t_bool                  is_message(t_message *message, uint64_t id, uint32_t nonce);





#endif
