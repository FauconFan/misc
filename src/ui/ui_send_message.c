#include "irc_udp.h"

void ui_send_stop(t_ui * ui) {
	t_ui_in_type stop;

	stop = UI_STOP;
	write(ui->fd_callback, &stop, sizeof(stop));
}

void ui_send_remote_message(t_ui * ui) {
	t_ui_in_type msg;

	msg = UI_MESSAGE;
	write(ui->fd_callback, &msg, sizeof(msg));
	write(ui->fd_callback, &(ui->len), sizeof(ui->len));
	write(ui->fd_callback, ui->line, ui->len);
	ui_init_line(ui);
}
