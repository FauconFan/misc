#include "irc_udp.h"

t_buffer_tlv_ip * buffer_alloc(t_ip_port ip_port) {
	t_buffer_tlv_ip * buffer = malloc(sizeof(t_buffer_tlv_ip));

	if (buffer == NULL)
		return (NULL);

	ip_port_assign(&buffer->ip_port, &ip_port);
	buffer->tlv_builder = tlvb_alloc();
	if (buffer->tlv_builder == NULL) {
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

void                buffer_free(t_buffer_tlv_ip * buffer) {
	tlvb_free(buffer->tlv_builder);
	free(buffer);
}

void                buffer_print(t_buffer_tlv_ip * buffer, int fd) {
	dprintf(fd, "buffer_tlv_ip { ip_port : ");
	ip_port_print(buffer->ip_port, fd);
	dprintf(fd, ", tlv_builder");
	iovb_print(buffer->tlv_builder->builder, fd);
	dprintf(fd, "}\n");
}

static t_bool       buffer_is_ip(t_buffer_tlv_ip * buffer, t_ip_port * ip_port) {
	return (ip_port_is_eq(&buffer->ip_port, ip_port));
}

// regarder si ça existe deja
//      si oui : juste add
//      si non : créer et add
t_buffer_tlv_ip * buffer_search(t_list * li_buffer_tlv_ip, t_ip_port ip_port) {
	t_buffer_tlv_ip * buffer = lst_findp(li_buffer_tlv_ip, (t_bool(*)(void *, void *))buffer_is_ip, &ip_port);

	if (buffer == NULL) {
		buffer = buffer_alloc(ip_port);
		lst_add(li_buffer_tlv_ip, buffer);
	}

	return (buffer);
}
