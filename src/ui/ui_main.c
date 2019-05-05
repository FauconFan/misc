#include "irc_udp.h"

static void    ui_treat_buffer(t_ui * ui) {
	char * tmp;
	char * line;
	size_t s;

	while ((tmp = strchr(ui->buffer_in, '\n')) != NULL) {
		s    = tmp - ui->buffer_in;
		line = strndup(ui->buffer_in, s);
		strreplace(&line, "\t", "    ");
		dprintf(ui->fd_log, "%s\n", line);
		if (ui->with_ncurses == FALSE) {
			printf("%s\n", line);
		}
		lst_add(ui->li_messages, line);
		tmp = strdup(ui->buffer_in + s + 1);
		free(ui->buffer_in);
		ui->buffer_in = tmp;
	}
}

static void ui_check_message(t_ui * ui) {
	char buff[1025];
	char * tmp;

	while (1) {
		memset(buff, 0, 1025);
		if (read(ui->fd_ui, buff, 1024) < 0)
			break;
		tmp = strjoin(ui->buffer_in, buff);
		free(ui->buffer_in);
		ui->buffer_in = tmp;
	}
	ui_treat_buffer(ui);
}

static void ui_check_stop(t_ui * ui) {
	char buff;

	ui->has_received_stop = (read(ui->fd_stop, &buff, sizeof(buff)) != -1);
}

static void ui_send_stop(t_ui * ui) {
	t_ui_type stop;

	stop = UI_STOP;
	write(ui->fd_callback, &stop, sizeof(stop));
}

static void ui_send_remote_message(t_ui * ui) {
	t_ui_type msg;

	msg = UI_MESSAGE;
	write(ui->fd_callback, &msg, sizeof(msg));
	write(ui->fd_callback, &(ui->len), sizeof(ui->len));
	write(ui->fd_callback, ui->line, ui->len);
	ui_init_line(ui);
}

static t_bool handle_new_charac(t_ui * ui, int actu) {
	if (actu == '\n') {
		if (strcmp(ui->line, "QUIT") == 0) {
			return (FALSE);
		}
		ui_send_remote_message(ui);
	}
	else if (actu == 127) {
		if (ui->len != 0)
			ui->line[--ui->len] = 0;
	}
	else if (isascii(actu)) {
		ui->line[ui->len++] = actu;
	}
	return (TRUE);
}

static void ui_main_loop_with_ncurses(t_ui * ui) {
	initscr();
	echo();
	timeout(TIMEOUT_READ);

	while (ui->has_received_stop == FALSE) {
		int actu;

		ui_check_message(ui);
		ui_check_stop(ui);
		ui_print(ui);
		refresh();
		actu = getch();
		if (actu != ERR) {
			if (handle_new_charac(ui, actu) == FALSE)
				break;
		}
	}

	endwin();
}

static void ui_main_loop_no_ncurses(t_ui * ui, int fd_stdin_custom_get, int fd_stdin_custom_stop) {
	while (ui->has_received_stop == FALSE) {
		int actu;

		ui_check_message(ui);
		ui_check_stop(ui);
		actu = ui_getstdin_custom(fd_stdin_custom_get);
		if (actu == ERR) { // sleep if there is no read
			usleep(TIMEOUT_READ * 1000);
		}
		else {
			if (handle_new_charac(ui, actu) == FALSE)
				break;
			ui_getstdin_continue(fd_stdin_custom_stop);
		}
	}

	ui_getstdin_stop(fd_stdin_custom_stop);
	sleep(1);
}

void        ui_main(t_bool with_ncurses, int fd_ui, int fd_callback, int fd_stop) {
	t_ui * ui;
	int exit_code;
	int fd_stdin_custom_get  = 0;
	int fd_stdin_custom_stop = 0;

	exit_code = 0;
	if (with_ncurses == FALSE) {
		if (ui_stdin_custom_setup(&fd_stdin_custom_get, &fd_stdin_custom_stop) == FALSE) {
			printf("fail setup stdin custom");
			exit_code = 1;
			close(fd_ui);
			close(fd_callback);
			close(fd_stop);
		}
	}
	if ((ui = ui_alloc(with_ncurses, fd_ui, fd_callback, fd_stop)) == NULL) {
		exit_code = 1;
	}
	else {
		if (with_ncurses) {
			ui_main_loop_with_ncurses(ui);
		}
		else {
			ui_main_loop_no_ncurses(ui, fd_stdin_custom_get, fd_stdin_custom_stop);
			close(fd_stdin_custom_get);
			close(fd_stdin_custom_stop);
		}

		if (ui->has_received_stop == FALSE)
			ui_send_stop(ui);

		sleep(1); // Sleep to let the super process to quit properly without any SIGPIPE.
		ui_free(ui);
	}
	exit(exit_code);
} /* ui_main */
