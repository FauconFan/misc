#include "irc_udp.h"


t_acquit_message        *a_message_alloc(uint64_t id, uint32_t nonce){
    t_acquit_message *a_message = malloc(sizeof(t_acquit_message));
    if (a_message == NULL)
        return NULL;
    a_message->sender_id = id;
    a_message->nonce = nonce;
    a_message->no_response = 0;
    a_message->next_time = raise(a_message->no_response);

    return a_message;
}


void                    a_message_free(t_acquit_message *a_message){
    free(a_message);
}


void                    a_message_no_response(t_acquit_message *a_message){
    a_message->no_response = a_message->no_response +1;
    a_message->next_time = raise(a_message->no_response);
}


t_bool                  is_a_message(t_acquit_message *a_message, uint64_t id, uint32_t nonce){
    return (a_message->sender_id == id && a_message->nonce == nonce);
}
