#include "irc_udp.h"

t_neighbour     *nei_alloc(uint64_t id, uint16_t port, uint8_t ip[16]){
    t_neighbour *nei =malloc(sizeof(t_neighbour));
    if (nei == NULL)
        return NULL;
    nei-> id = id;
    nei->port = port;

    memcpy(nei->ip, ip, 16);

    struct timeval now;
    gettimeofday(&now, NULL);
    // je suppose que quand on ajoute un voisin on initilaise tous les temps à maintenant
    // si on devient voisin c'est qu'on vient de recevoir un hello court et qu'on a reçu un hello long
    // ou inversement
    //   Est ce que c'est bien ?
    nei->last_hello = now;
    nei->last_hello_long = now;
    nei->our_last_hello = now;

    return nei;
}

void            nei_free(t_neighbour *nei){
    free(nei);
}


t_bool          nei_is_id(t_neighbour *nei, uint64_t id){
    return(nei->id == id);
}
