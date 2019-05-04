#include "irc_udp.h"

void parse_hello(uint8_t * tlv, t_neighbour ** nei, t_ip_port ip_port) {
	uint16_t len;
	uint64_t source_id;
	uint64_t dest_id;
	struct timeval now;
	t_neighbour * nei2;
	t_buffer_tlv_ip * buffer;

	gettimeofday(&now, NULL);

	len = tlv[1];
	if (len != 8 && len != 16) {
		dprintf(ui_getfd(), "Inconsistent hello message\n");
		dprintf(ui_getfd(), "Wrong len %d\n", len);
	}
	else if (len == 8) {
		source_id = *(uint64_t *) (tlv + 2);
		dprintf(ui_getfd(), "HELLO SHORT Source-id: %016lx\n", source_id);
		if (*nei != NULL) {
			(*nei)->last_hello = now;
		}
		else {
			if (lst_size(g_env->li_neighbours) < NB_NEI_MAX) {
				buffer = buffer_search(g_env->li_buffer_tlv_ip, ip_port);
				tlvb_add_hello_long(buffer->tlv_builder, g_env->id, source_id);
			}
			else {
				lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip_port));
			}
		}
	}
	else if (len == 16) {
		source_id = *(uint64_t *) (tlv + 2);
		dest_id   = *(uint64_t *) (tlv + 10);
		dprintf(ui_getfd(), "HELLO LONG Source-id: %016lx, Dest-id: %016lx\n", source_id, dest_id);
		if (*nei != NULL) {
			(*nei)->last_hello      = now;
			(*nei)->last_hello_long = now;
		}
		else {
			nei2 = nei_alloc(source_id, ip_port);
			lst_remove_ifp(g_env->li_potential_neighbours, (t_bool(*)(void *, void *))pot_nei_is, &ip_port);
			lst_add(g_env->li_neighbours, nei2);
			*nei = nei2;

			// Resend hello long first time
			buffer = buffer_search(g_env->li_buffer_tlv_ip, nei2->ip_port);
			tlvb_add_hello_long(buffer->tlv_builder, g_env->id, source_id);
		}
	}
} /* parse_hello */
