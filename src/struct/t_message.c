#include "irc_udp.h"



t_message               *message_alloc(uint64_t id, uint32_t nonce, uint8_t type, uint8_t length, uint8_t *text){
    t_message *message = malloc(sizeof(t_message));
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


void                    message_free(t_message *message){
    free(message->text);
    free(message);
}

void                    message_print(t_message *message){
    printf("message { sender_id : %016lx, nonce : %x, type : %d, length : %d, msg : ", message->sender_id, message->nonce, message->type, message->length);
    if (message->type != 0)
        printf("No printable message");
    else
        printf("\"%.*s\"", message->length, message->text);
    printf("}");
}

t_bool                  is_message(t_message *message, uint64_t id, uint32_t nonce){
    return (message->sender_id == id && message->nonce == nonce);
}
