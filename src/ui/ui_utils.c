#include "irc_udp.h"

t_ui * ui_alloc(char * pseudo) {
	t_ui * ui;

	if ((ui = (t_ui *) malloc(sizeof(t_ui))) == NULL)
		return (NULL);

	ui->pseudo      = strdup(pseudo);
	ui->li_messages = lst_alloc(free, NULL);
	ui_init_line(ui);
	memset(ui->buffer_in, 0, sizeof(ui->buffer_in) / sizeof(ui->buffer_in[0]));
	return (ui);
}

void    ui_free(t_ui * ui) {
	lst_free(ui->li_messages);
	free(ui->pseudo);
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
	size_t len;

	while ((tmp = strchr(ui->buffer_in, '\n')) != NULL) {
		s    = tmp - ui->buffer_in;
		len  = strlen(ui->buffer_in);
		line = strndup(ui->buffer_in, s);
		strreplace(&line, "\t", "    ");
		dprintf(g_log, "%s\n", line);
		lst_add(ui->li_messages, line);
		memmove(ui->buffer_in, ui->buffer_in + s + 1, len - s);
		memset(ui->buffer_in + len - s, 0, s);
	}
}
