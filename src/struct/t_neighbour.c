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
    nei->next_hello = now;
    nei->next_hello.tv_sec += 30;

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
    printf(", next_hello ");
    print_time_val(nei->next_hello);
    printf("}");
}


t_bool          nei_is_id(t_neighbour *nei, uint64_t id){
    return(nei->id == id);
}

static void     parcours_nei(t_neighbour *nei, struct timeval * tv) {
    struct timeval *tmp;
    tmp = min_time(*tv, nei->next_hello);
    time_assign(tv, tmp);
}

struct timeval         nei_get_min_time(t_list *li_neighbours) {
    struct timeval tv = ((t_neighbour *)lst_top(li_neighbours))->next_hello;

    lst_iterp(li_neighbours, (void (*)(void *, void *))parcours_nei, &tv);
    return tv;
}
