#include "irc_udp.h"

static t_bool   search_acq(t_acquit * acq, uint64_t sender_id) {
	return (acq->sender_id == sender_id);
}

static t_bool   check_message(t_message * msg) {
	if (timeval_lessthan(g_env->now, msg->check_timeout)) {
		return (FALSE);
	}
	if (lst_findp(g_env->li_acquit, (t_bool(*)(void *, void *))search_acq, (void *) msg->sender_id) == NULL) {
		dprintf(ui_getfd_log(), "Found message to delete : ");
		message_print(msg, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");
		return (TRUE);
	}
	msg->check_timeout.tv_sec += TIMEOUT_CHECK_MSG;
	return (FALSE);
}

void           ps8_delete_messages_if_too_late() {
	dprintf(ui_getfd_log(), "Step 8 - Delete old messages to free space\n");
	lst_removeall_if(g_env->li_messages, (t_bool(*)(void *))check_message);
}
