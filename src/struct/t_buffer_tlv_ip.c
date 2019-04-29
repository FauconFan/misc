#include "irc_udp.h"


t_buffer_tlv_ip     *buffer_alloc(uint8_t ip[16], uint16_t port){
    t_buffer_tlv_ip *buffer = malloc(sizeof(t_buffer_tlv_ip));
    if (buffer == NULL)
        return NULL;
    memcpy(buffer->ip, ip, 16);
    buffer->port = port;
    buffer->tlv_builder = tlvb_alloc();
    return buffer;
}


void                buffer_free(t_buffer_tlv_ip *buffer){
    tlvb_free(buffer->tlv_builder);
    free(buffer);
}

void                buffer_print(t_buffer_tlv_ip *buffer){
    printf("buffer_tlv_ip { id : ");
    for (size_t i = 0; i < 16; ++i) {
        if (i != 0)
            printf(" ");
        printf("%.2x", buffer->ip[i]);
    }
    printf(", port : %d, tlv_builder : \n", buffer->port);
    iovb_print(buffer->tlv_builder->msg);
    printf("} :\n" );
}

typedef struct              s_ip_port{
    uint8_t         ip[16];
    uint16_t        port;
}                           t_ip_port;

static t_bool       buffer_is_ip(t_buffer_tlv_ip *buffer, t_ip_port *ip_port){
    return (memcmp(buffer->ip, ip_port->ip, 16)==0 && buffer->port == ip_port->port);
}

// regarder si ça existe deja
//      si oui : juste add
//      si non : créer et add
t_buffer_tlv_ip     *buffer_search(uint8_t ip[16], uint16_t port){
        t_ip_port ip_port;
        memcpy(&ip_port.ip, ip, 16);
        ip_port.port = port;

        t_buffer_tlv_ip *buffer = lst_findp(g_env->li_buffer_tlv_ip, (t_bool (*) (void *, void *))buffer_is_ip, &ip_port);

        if(buffer == NULL) {
            buffer = buffer_alloc(ip, port);
            lst_add(g_env->li_buffer_tlv_ip, buffer);
        }

        return buffer;

}
