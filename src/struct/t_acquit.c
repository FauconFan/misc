#include "irc_udp.h"


t_acquit                *acquit_alloc(uint64_t id, uint32_t nonce){
    t_acquit *acquit = malloc(sizeof(t_acquit));
    if (acquit == NULL)
        return NULL;
    acquit->sender_id = id;
    acquit->nonce = nonce;
    acquit->no_response = 0;
    acquit->next_time = raise(acquit->no_response);

    return acquit;
}


void                    acquit_free(t_acquit *acquit){
    free(acquit);
}

void                    acquit_print(t_acquit *acquit) {
    printf("acquit { sender_id : %016lx, nonce : %x, next_time : ", acquit->sender_id, acquit->nonce);
    print_time_val(acquit->next_time);
    printf(", no_respons : %d }", acquit->no_response);
}

void                    acquit_no_response(t_acquit *acquit){
    acquit->no_response = acquit->no_response +1;
    acquit->next_time = raise(acquit->no_response);
}


t_bool                  is_acquit(t_acquit *acquit, uint64_t id, uint32_t nonce){
    return (acquit->sender_id == id && acquit->nonce == nonce);
}
