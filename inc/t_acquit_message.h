// messages envoyés non acquittés

// (id, nonce) cf 'messages reçus' --> chercher le contenu dans les messages reçus
// date limite avant renvoie
// nb fois ou on a pris des vents


#ifndef T_ACQUIT_MESSAGE_H
#define T_ACQUIT_MESSAGE_H

#include "irc_udp.h"

typedef struct      s_acquit_message{
    uint64_t        id;
    uint32_t        nonce;
    struct timeval  next_time;
    uint8_t         no_response;
}                   t_acquit_message;

t_acquit_message        *a_message_alloc(uint64_t id, uint32_t nonce);
void                    a_message_free(t_acquit_message *a_message);

// incrémenter le next_time et (no_response +1)
t_bool                  *a_message_no_response(t_acquit_message *a_message);

// prédicat d'égalité
t_bool                  is_a_message(t_acquit_message *a_message, uint64_t id, uint32_t nonce);

#endif
