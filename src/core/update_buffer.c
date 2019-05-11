#include "irc_udp.h"

void            update_buffer(void) {
	dprintf(ui_getfd_log(), "current time : ");
	timeval_print(g_env->now, ui_getfd_log());
	dprintf(ui_getfd_log(), "\n");

	dprintf(ui_getfd_log(), "   8 PROCESS STEPS\n");

	ps1_delete_old_pot_neighbours();
	ps2_connect_new_neighbour();
	ps3_go_away_old_neighbours();
	ps4_send_long_hello();
	ps5_go_away_ack_missing();
	ps6_resend_messages_non_acquitted();
	ps7_send_random_neighbour_tlv();
	ps8_delete_messages_if_too_late();
} /* update_buffer */
