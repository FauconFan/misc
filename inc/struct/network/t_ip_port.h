#ifndef T_IP_PORT_H
#define	T_IP_PORT_H

typedef struct      s_ip_port{
	uint8_t  ip[16];
	uint16_t port;
}                   t_ip_port;

void        ip_port_assign_sockaddr6(t_ip_port * ip_port, struct sockaddr_in6 in6);
void        ip_port_assign(t_ip_port * ip_port1, t_ip_port * ip_port2);

t_bool      ip_port_is_eq(t_ip_port * ip_port1, t_ip_port * ip_port2);

void        ip_port_print(t_ip_port ip_port, int fd);

#endif // ifndef T_IP_PORT_H
