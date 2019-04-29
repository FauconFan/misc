#ifndef T_BUFFER_TLV_IP_H
#define	T_BUFFER_TLV_IP_H

typedef struct      s_buffer_tlv_ip{
	uint8_t         ip[16];
	uint16_t        port;
	t_tlv_builder * tlv_builder;
}                   t_buffer_tlv_ip;

// alloc, free

t_buffer_tlv_ip * buffer_alloc(uint8_t ip[16], uint16_t port);

void                buffer_free(t_buffer_tlv_ip * buffer);
// print

void                buffer_print(t_buffer_tlv_ip * buffer, int fd);


t_buffer_tlv_ip * buffer_search(uint8_t ip[16], uint16_t port);


#endif // ifndef T_BUFFER_TLV_IP_H
