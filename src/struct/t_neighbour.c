#include "irc_udp.h"

t_neighbour     *nei_alloc(uint64_t id, uint8_t ip[16], uint16_t port){
    t_neighbour *nei =malloc(sizeof(t_neighbour));
    if (nei == NULL)
        return NULL;
    nei->id = id;
    nei->port = port;

    memcpy(nei->ip, ip, 16);

    struct timeval now;
    gettimeofday(&now, NULL);
    nei->last_hello = now;
    nei->last_hello_long = now;
    nei->our_last_hello = now;

    return nei;
}

void            nei_free(t_neighbour *nei){
    free(nei);
}

void            nei_print(t_neighbour *nei) {
    printf("neighbour { id : %016lx, port : %d, ip : ", nei->id, nei->port);
    for (size_t i = 0; i < 16; ++i) {
        if (i != 0)
            printf(" ");
        printf("%.2x", nei->ip[i]);
    }
    printf(", last hello ");
    print_time_val(nei->last_hello);
    printf(", last hello long ");
    print_time_val(nei->last_hello_long);
    printf(", our last hello ");
    print_time_val(nei->our_last_hello);
    printf("}");
}


t_bool          nei_is_id(t_neighbour *nei, uint64_t id){
    return(nei->id == id);
}
