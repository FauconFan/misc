#ifndef T_BUFFER_TLV_IP_H
#define	T_BUFFER_TLV_IP_H

typedef struct      s_buffer_tlv_ip{
	t_ip_port       ip_port;
	t_tlv_builder * tlv_builder;
}                   t_buffer_tlv_ip;

// alloc, free

t_buffer_tlv_ip * tlvip_alloc(t_ip_port ip_port);
void                tlvip_free(t_buffer_tlv_ip * buffer);

void                tlvip_print(t_buffer_tlv_ip * buffer, int fd);

t_buffer_tlv_ip * tlvip_search(t_list * li_buffer_tlv_ip, t_ip_port ip_port);

#endif // ifndef T_BUFFER_TLV_IP_H
