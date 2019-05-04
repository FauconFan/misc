#include "irc_udp.h"

static void ui_check_message(t_ui * ui, int fd_ui, int fd_log) {
	char buff[1025];
	char * tmp;

	while (1) {
		memset(buff, 0, 1025);
		if (read(fd_ui, buff, 1024) < 0)
			break ;
		tmp = strjoin(ui->buffer_in, buff);
		free(ui->buffer_in);
		ui->buffer_in = tmp;
	}
	ui_treat_buffer(ui, fd_log);
}

static void ui_check_stop(int fd_stop, t_bool * has_received_stop) {
	char buff;

	*has_received_stop = (read(fd_stop, &buff, sizeof(buff)) != -1);
}

static void ui_send_stop(int fd_callback) {
	t_ui_type stop;

	stop = UI_STOP;
	write(fd_callback, &stop, sizeof(stop));
}

static void ui_send_remote_message(int fd_callback, t_ui * ui) {
	t_ui_type msg;

	msg = UI_MESSAGE;
	write(fd_callback, &msg, sizeof(msg));
	write(fd_callback, &(ui->len), sizeof(ui->len));
	write(fd_callback, ui->line, ui->len);
	ui_init_line(ui);
}

static void	ui_main_loop(t_ui * ui, int fd_ui, int fd_callback, int fd_stop, int fd_log, t_bool *has_received_stop) {
	*has_received_stop = FALSE;
	int fd_stdin_custom_get = 0;
	int fd_stdin_custom_stop = 0;

	if (ui->with_ncurses) {
		initscr();
		echo();
		timeout(TIMEOUT_READ);
	}
	else {
		if (ui_stdin_custom_setup(&fd_stdin_custom_get, &fd_stdin_custom_stop) == FALSE) {
			printf("fail setup stdin custom");
			return ;
		}
	}

	while (*has_received_stop == FALSE) {
		int actu;

		ui_check_message(ui, fd_ui, fd_log);
		ui_check_stop(fd_stop, has_received_stop);
		if (ui->with_ncurses) {
			ui_print(ui);
			refresh();
			actu = getch();
		}
		else {
			actu = ui_getstdin_custom(fd_stdin_custom_get);
			if (actu == ERR) // sleep if there is no read
				usleep(TIMEOUT_READ * 1000);
		}
		if (actu != ERR) {
			if (actu == '\n') {
				if (strcmp(ui->line, "QUIT") == 0) {
					break;
				}
				ui_send_remote_message(fd_callback, ui);
			}
			else if (actu == 127) {
				if (ui->len != 0)
					ui->line[--ui->len] = 0;
			}
			else if (isascii(actu))
				ui->line[ui->len++] = actu;

			if (ui->with_ncurses == FALSE)
				ui_getstdin_continue(fd_stdin_custom_stop);
		}
	}

	if (ui->with_ncurses) {
		endwin();
	}
	else {
		ui_getstdin_stop(fd_stdin_custom_stop);
		sleep(1);
		close(fd_stdin_custom_get);
		close(fd_stdin_custom_stop);
	}
}

int        ui_main(t_bool with_ncurses, int fd_ui, int fd_callback, int fd_stop) {
	t_ui * ui;
	int fd_log;
	t_bool has_received_stop;

	if ((ui = ui_alloc(g_pseudo, with_ncurses)) == NULL || ui_log_setup(&fd_log) == FALSE)
		return (1);

	ui_main_loop(ui, fd_ui, fd_callback, fd_stop, fd_log, &has_received_stop);
	ui_free(ui);

	if (has_received_stop == FALSE)
		ui_send_stop(fd_callback);

	sleep(1); // Sleep to let the super process to quit properly without any SIGPIPE.

	close(fd_ui);
	close(fd_callback);
	close(fd_stop);
	free(g_pseudo);
	close(fd_log);
	return (0);
} /* ui_main */
