// messages envoyés non acquittés

// (id, nonce) cf 'messages reçus' --> chercher le contenu dans les messages reçus
// date limite avant renvoie
// nb fois ou on a pris des vents


#ifndef T_ACQUIT_H
#define T_ACQUIT_H

#include "irc_udp.h"

typedef struct      s_acquit {
    uint64_t        sender_id;
    uint32_t        nonce;
    struct timeval  next_time;
    uint8_t         no_response;
}                   t_acquit;

t_acquit                *acquit_alloc(uint64_t id, uint32_t nonce);
void                    acquit_free(t_acquit *acquit);

void                    acquit_print(t_acquit *acquit);

// incrémenter le next_time et (no_response +1)
void                    acquit_no_response(t_acquit *acquit);

// prédicat d'égalité
t_bool                  is_acquit(t_acquit *acquit, uint64_t id, uint32_t nonce);

struct timeval          acquit_get_min_time(t_list *li_acquit);

#endif
