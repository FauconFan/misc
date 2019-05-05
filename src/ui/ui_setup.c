#include "irc_udp.h"

static int g_fd_screen   = -1;
static int g_fd_log      = -1;
static int g_fd_callback = -1;
static int g_fd_send     = -1;

int     ui_getfd_screen(void) {
	return (g_fd_screen);
}

int     ui_getfd_log(void) {
	return (g_fd_log);
}

int     ui_getfd_callback(void) {
	return (g_fd_callback);
}

void    ui_receive(t_ui_in * in) {
	size_t len;

	in->type = UI_OK;
	read(g_fd_callback, &(in->type), sizeof(in->type));
	switch (in->type) {
		case UI_OK:
			in->u.ok = TRUE;
			break;
		case UI_STOP:
			in->u.ok = FALSE;
			break;
		case UI_MESSAGE:
			read(g_fd_callback, &len, sizeof(len));
			in->u.message = strnew(len);
			read(g_fd_callback, in->u.message, len);
			break;
	}
}

void    ui_down(void) {
	if (g_fd_screen != -1) {
		close(g_fd_screen);
		g_fd_screen = -1;
	}
	if (g_fd_log != -1) {
		close(g_fd_log);
		g_fd_log = -1;
	}
	if (g_fd_callback != -1) {
		close(g_fd_callback);
		g_fd_callback = -1;
	}
	if (g_fd_send != -1) {
		write(g_fd_send, &g_fd_send, sizeof(g_fd_send));
		sleep(1);
		close(g_fd_send);
		g_fd_send = -1;
	}
}

t_bool    ui_setup(t_bool with_ncurses, t_bool with_logs) {
	int fds_screen[2];
	int fds_log[2];
	int fds_callback[2];
	int fds_stop[2];
	pid_t pid_child;

	if (pipe2(fds_screen, O_NONBLOCK) == -1) {
		return (FALSE);
	}
	else if (pipe2(fds_log, O_NONBLOCK) == -1) {
		close(fds_screen[0]);
		close(fds_screen[1]);
		return (FALSE);
	}
	else if (pipe2(fds_callback, O_NONBLOCK) == -1) {
		close(fds_screen[0]);
		close(fds_screen[1]);
		close(fds_log[0]);
		close(fds_log[1]);
		return (FALSE);
	}
	else if (pipe2(fds_stop, O_NONBLOCK) == -1) {
		close(fds_screen[0]);
		close(fds_screen[1]);
		close(fds_log[0]);
		close(fds_log[1]);
		close(fds_callback[0]);
		close(fds_callback[1]);
		return (FALSE);
	}

	pid_child = fork();
	if (pid_child == -1) {
		close(fds_screen[0]);
		close(fds_screen[1]);
		close(fds_log[0]);
		close(fds_log[1]);
		close(fds_callback[0]);
		close(fds_callback[1]);
		close(fds_stop[0]);
		close(fds_stop[1]);
		return (FALSE);
	}

	if (pid_child == 0) {
		close(fds_screen[1]);
		close(fds_log[1]);
		close(fds_callback[0]);
		close(fds_stop[1]);

		ui_main(with_ncurses, with_logs, fds_screen[0], fds_log[0], fds_callback[1], fds_stop[0]);
		exit(1);
	}
	else {
		close(fds_screen[0]);
		close(fds_log[0]);
		close(fds_callback[1]);
		close(fds_stop[0]);

		g_fd_screen   = fds_screen[1];
		g_fd_log      = fds_log[1];
		g_fd_callback = fds_callback[0];
		g_fd_send     = fds_stop[1];
	}
	return (TRUE);
} /* ui_setup */
