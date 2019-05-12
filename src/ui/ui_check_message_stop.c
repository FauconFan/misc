#include "irc_udp.h"

static void    ui_treat_buffer_abstract(t_ui * ui, char ** ptrbuff, void(* callback)(t_ui * ui, char * line)) {
	char * tmp;
	char * line;
	size_t s;

	while ((tmp = strchr(*ptrbuff, '\n')) != NULL) {
		s    = tmp - *ptrbuff;
		line = strndup(*ptrbuff, s);

		strreplace(&line, "\t", "    ");

		callback(ui, line);

		tmp = strdup(*ptrbuff + s + 1);
		free(*ptrbuff);
		*ptrbuff = tmp;
		free(line);
	}
}

static void     ui_callback_buffer_screen(t_ui * ui, char * line) {
	dprintf(ui->fd_log_file, "NORMAL: %s\n", line);
	lst_add(ui->li_messages, strdup(line));
	if (ui->with_ncurses == FALSE) {
		printf("%s\n", line);
	}
}

static void     ui_callback_buffer_logs(t_ui * ui, char * line) {
	dprintf(ui->fd_log_file, "INFO:   %s\n", line);
	if (ui->with_logs) {
		lst_add(ui->li_messages, strdup(line));
		if (ui->with_ncurses == FALSE) {
			printf("%s\n", line);
		}
	}
}

static void ui_update_buffer(int fd, char ** ptrbuff) {
	char buff[1025];
	char * tmp;
	int	ret;

	while (1) {
		memset(buff, 0, 1025);
		ret = read(fd, buff, 1024);
		if (ret <= 0)
			break;
		tmp = strjoin(*ptrbuff, buff);
		free(*ptrbuff);
		*ptrbuff = tmp;
	}
}

void ui_check_message(t_ui * ui) {
	ui_update_buffer(ui->fd_screen, &(ui->buffer_screen));
	ui_update_buffer(ui->fd_log_new, &(ui->buffer_logs));
	ui_treat_buffer_abstract(ui, &(ui->buffer_screen), ui_callback_buffer_screen);
	ui_treat_buffer_abstract(ui, &(ui->buffer_logs), ui_callback_buffer_logs);
}

void ui_check_stop(t_ui * ui) {
	char buff;

	ui->has_received_stop = (read(ui->fd_send, &buff, sizeof(buff)) != -1);
}
