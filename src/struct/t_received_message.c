#include "irc_udp.h"



t_received_message      *message_alloc(uint64_t id, uint32_t nonce, uint8_t type, uint8_t length, uint8_t *text){
    t_received_message *message = malloc(sizeof(t_received_message));
    if (message == NULL)
        return (NULL);
    if ((message->text = malloc(length)) == NULL) {
        free(message);
        return (NULL);
    }
    message->sender_id = id;
    message->nonce = nonce;
    message->type = type;
    message->length = length;
    memcpy(message->text, text, length);

    return (message);
}


void                    message_free(t_received_message *message){
    free(message->text);
    free(message);
}

void                    print_message(t_received_message *message){
    printf("%.*s\n", message->length, message->text);
}


t_bool                  is_message(t_received_message *message, uint64_t id, uint32_t nonce){
    return (message->sender_id == id && message->nonce == nonce);
}
