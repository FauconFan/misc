#include "irc_udp.h"

t_ui * ui_alloc(t_bool with_ncurses, t_bool with_logs, int fd_screen, int fd_log, int fd_callback, int fd_send) {
	t_ui * ui;

	if ((ui = (t_ui *) malloc(sizeof(t_ui))) == NULL)
		return (NULL);

	memset(ui, 0, sizeof(*ui));
	if (ui_log_setup(&(ui->fd_log_file)) == FALSE) {
		free(ui);
		return (NULL);
	}
	ui->pseudo        = strdup(g_pseudo);
	ui->with_ncurses  = with_ncurses;
	ui->with_logs     = with_logs;
	ui->li_messages   = lst_alloc(free, NULL);
	ui->buffer_screen = strnew(0);
	ui->buffer_logs   = strnew(0);
	ui_init_line(ui);
	ui->fd_screen         = fd_screen;
	ui->fd_log_new        = fd_log;
	ui->fd_callback       = fd_callback;
	ui->fd_send           = fd_send;
	ui->has_received_stop = FALSE;
	return (ui);
}

void    ui_free(t_ui * ui) {
	lst_free(ui->li_messages);
	free(ui->pseudo);
	free(ui->buffer_screen);
	free(ui->buffer_logs);
	close(ui->fd_screen);
	close(ui->fd_log_new);
	close(ui->fd_callback);
	close(ui->fd_send);
	close(ui->fd_log_file);
	free(ui);
}

void    ui_init_line(t_ui * ui) {
	ui->len = 0;
	memset(ui->line, 0, sizeof(ui->line) / sizeof(ui->line[0]));
}
