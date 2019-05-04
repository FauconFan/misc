#ifndef CORE_H
#define	CORE_H

t_bool      get_sockaddr_juliusz(
  struct sockaddr ** sock_addr,
  socklen_t *        sock_len);

t_bool      get_sockaddr(
  const char *       node,
  const char *       service,
  struct sockaddr ** sock_addr,
  socklen_t *        sock_len);

void    core_loop();

int     build_socket(void);


t_bool  select_treat_input(void);
void    update_buffer(void);
void    clear_buffer(void);

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

#endif // ifndef CORE_H
