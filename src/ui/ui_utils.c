#include "irc_udp.h"

t_ui * ui_alloc(char * pseudo, t_bool with_ncurses) {
	t_ui * ui;

	if ((ui = (t_ui *) malloc(sizeof(t_ui))) == NULL)
		return (NULL);

	memset(ui, 0, sizeof(*ui));
	ui->pseudo      = strdup(pseudo);
	ui->with_ncurses = with_ncurses;
	ui->li_messages = lst_alloc(free, NULL);
	ui->buffer_in = strnew(0);
	ui_init_line(ui);
	return (ui);
}

void    ui_free(t_ui * ui) {
	lst_free(ui->li_messages);
	free(ui->pseudo);
	free(ui->buffer_in);
	free(ui);
}

void    ui_init_line(t_ui * ui) {
	ui->len = 0;
	memset(ui->line, 0, sizeof(ui->line) / sizeof(ui->line[0]));
}

void    ui_treat_buffer(t_ui * ui, int g_log) {
	char * tmp;
	char * line;
	size_t s;

	while ((tmp = strchr(ui->buffer_in, '\n')) != NULL) {
		s    = tmp - ui->buffer_in;
		line = strndup(ui->buffer_in, s);
		strreplace(&line, "\t", "    ");
		dprintf(g_log, "%s\n", line);
		if (ui->with_ncurses == FALSE) {
			printf("%s\n", line);
		}
		lst_add(ui->li_messages, line);
		tmp = strdup(ui->buffer_in + s + 1);
		free(ui->buffer_in);
		ui->buffer_in = tmp;
	}
}
