#ifndef CORE_H
#define	CORE_H

t_bool      get_sockaddr_juliusz(struct sockaddr_in6 * sock_addr);

t_bool      get_sockaddr(
  const char *          node,
  const char *          service,
  struct sockaddr_in6 * sock_addr);

void    core_loop();

int     build_socket(int port);
int     build_socket_multicast(void);
t_bool build_sockaddr_multicast(struct sockaddr_in6 * sin6);

void      send_multicast(void);

t_bool  select_treat_input(void);
void    update_buffer(void);
void    clear_buffer(void);

t_bool  parse_args(int argc, char ** argv, t_bool * with_ncurses, t_bool * with_log, t_bool * with_juliusz_init,
  int * port);

// env_manip

typedef struct  s_id_nonce_msg{
	uint64_t sender_id;
	uint32_t nonce;
}               t_id_nonce_msg;

typedef struct  s_id_nonce_acq{
	uint64_t sender_id;
	uint32_t nonce;
	uint64_t dest_id;
}               t_id_nonce_acq;

void    env_build_min_time(struct timeval * res);
t_bool  env_has_already_received_msg(t_id_nonce_msg id_nonce);
void    env_remove_acquit_by_id_nonce(t_id_nonce_acq id_nonce);
t_bool  env_has_acquit_by_id_nonce(t_id_nonce_acq id_nonce_acq);
void    env_go_away_all();
void    env_erase_nei(t_neighbour * nei);
t_neighbour * env_search_nei(t_ip_port ipp);
t_neighbour * env_search_nei_by_acq(t_acquit * acq);
t_potential_neighbour * env_get_pot_nei_available(void);

// parse_tlv

void    parse_datagram(uint8_t * tlv, size_t len, t_neighbour * nei, t_ip_port ip_port);

void    parse_pad1(void);
void    parse_padN(uint8_t * tlv);
void    parse_hello(uint8_t * tlv, t_neighbour ** nei, t_ip_port ip_port);
void    parse_neighbour(uint8_t * tlv, t_neighbour * nei);
void    parse_data(uint8_t * tlv, t_neighbour * nei, t_ip_port ip_port);
void    parse_ack(uint8_t * tlv, t_neighbour * nei);
void    parse_goaway(uint8_t * tlv, t_neighbour * nei);
void    parse_warning(uint8_t * tlv, t_neighbour * nei);

// process_steps

void     ps1_delete_old_pot_neighbours(void);
void     ps2_connect_new_neighbour(void);
void     ps3_go_away_old_neighbours(void);
void     ps4_send_long_hello(void);
void     ps5_go_away_ack_missing(void);
void     ps6_resend_messages_non_acquitted(void);
void     ps7_send_random_neighbour_tlv(void);
void     ps8_delete_messages_if_too_late(void);

#endif // ifndef CORE_H
