#include "irc_udp.h"

static int g_fd_ui       = -1;
static int g_fd_callback = -1;
static int g_fd_stop     = -1;

int     ui_getfd(void) {
	return (g_fd_ui);
}

int     ui_getcallbackfd(void) {
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
	if (g_fd_ui != -1) {
		close(g_fd_ui);
		g_fd_ui = -1;
	}
	if (g_fd_callback != -1) {
		close(g_fd_callback);
		g_fd_callback = -1;
	}
	if (g_fd_stop != -1) {
		write(g_fd_stop, &g_fd_stop, sizeof(g_fd_stop));
		sleep(1);
		close(g_fd_stop);
		g_fd_stop = -1;
	}
}

t_bool    ui_setup(void) {
	int fds_ui[2];
	int fds_callback[2];
	int fds_stop[2];
	pid_t pid_child;

	if (pipe2(fds_ui, O_NONBLOCK) == -1) {
		return (FALSE);
	}
	else if (pipe2(fds_callback, O_NONBLOCK) == -1) {
		close(fds_ui[0]);
		close(fds_ui[1]);
		return (FALSE);
	}
	else if (pipe2(fds_stop, O_NONBLOCK) == -1) {
		close(fds_ui[0]);
		close(fds_ui[1]);
		close(fds_callback[0]);
		close(fds_callback[1]);
		return (FALSE);
	}

	pid_child = fork();
	if (pid_child == -1) {
		close(fds_ui[0]);
		close(fds_ui[1]);
		close(fds_callback[0]);
		close(fds_callback[1]);
		close(fds_stop[0]);
		close(fds_stop[1]);
		return (FALSE);
	}

	if (pid_child == 0) {
		close(fds_ui[1]);
		close(fds_callback[0]);
		close(fds_stop[1]);

		int ret = ui_main(fds_ui[0], fds_callback[1], fds_stop[0]);

		close(fds_ui[0]);
		close(fds_callback[1]);
		close(fds_stop[0]);
		exit(ret);
	}
	else {
		close(fds_ui[0]);
		close(fds_callback[1]);
		close(fds_stop[0]);

		g_fd_ui       = fds_ui[1];
		g_fd_callback = fds_callback[0];
		g_fd_stop     = fds_stop[1];
	}
	return (TRUE);
} /* ui_setup */
