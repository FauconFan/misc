#include "irc_udp.h"

t_ui * ui_alloc(t_bool with_ncurses, int fd_ui, int fd_callback, int fd_stop) {
	t_ui * ui;

	if ((ui = (t_ui *) malloc(sizeof(t_ui))) == NULL)
		return (NULL);

	memset(ui, 0, sizeof(*ui));
	if (ui_log_setup(&(ui->fd_log)) == FALSE) {
		free(ui);
		return (NULL);
	}
	ui->pseudo       = strdup(g_pseudo);
	ui->with_ncurses = with_ncurses;
	ui->li_messages  = lst_alloc(free, NULL);
	ui->buffer_in    = strnew(0);
	ui_init_line(ui);
	ui->fd_ui             = fd_ui;
	ui->fd_callback       = fd_callback;
	ui->fd_stop           = fd_stop;
	ui->has_received_stop = FALSE;
	return (ui);
}

void    ui_free(t_ui * ui) {
	lst_free(ui->li_messages);
	free(ui->pseudo);
	free(ui->buffer_in);
	close(ui->fd_ui);
	close(ui->fd_callback);
	close(ui->fd_stop);
	close(ui->fd_log);
	free(ui);
}

void    ui_init_line(t_ui * ui) {
	ui->len = 0;
	memset(ui->line, 0, sizeof(ui->line) / sizeof(ui->line[0]));
}
