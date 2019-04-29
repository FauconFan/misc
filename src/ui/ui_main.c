#include "irc_udp.h"

static void ui_check_message(t_ui * ui, int fd_ui) {
	size_t len;

	len = strlen(ui->buffer_in);
	if (read(fd_ui, ui->buffer_in + len, 1024 - len) > 0)
		ui_treat_buffer(ui);
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

void        ui_main(int fd_ui, int fd_callback) {
	t_ui * ui;

	// char        *pseudo;

	// write(1, "Enter your pseudonyme: ", 23);
	// if ((pseudo = ui_read_pseudo()) == NULL)
	//     return ;
	if ((ui = ui_alloc(strdup("pepe"))) == NULL)
		return;

	initscr();
	echo();
	timeout(30);

	while (1) {
		int actu;

		ui_check_message(ui, fd_ui);
		ui_print(ui);
		refresh();
		actu = getch();
		if (actu != ERR) {
			if (actu == '\n') {
				if (strcmp(ui->line, "QUIT") == 0)
					break;
				ui_send_remote_message(fd_callback, ui);
			}
			else if (actu == 127) {
				if (ui->len != 0)
					ui->line[--ui->len] = 0;
			}
			else if (isascii(actu) == 0) {
				continue;
			}
			else {
				ui->line[ui->len] = actu;
				ui->len++;
			}
		}
	}

	endwin();

	ui_free(ui);

	ui_send_stop(fd_callback);

	close(fd_ui);
	close(fd_callback);
	exit(0);
} /* ui_main */
