#include "irc_udp.h"

static void     ui_print_window(int nb_line, size_t nb_col_left) {
	move(0, 0);

	addch(ACS_ULCORNER);
	for (size_t j = 1; j < 3 + nb_col_left; ++j)
		addch(ACS_HLINE);
	addch(ACS_TTEE);
	for (int j = 4 + nb_col_left; j < COLS - 1; ++j)
		addch(ACS_HLINE);
	addch(ACS_URCORNER);
	for (int i = 1; i < LINES - 1 - nb_line - 1; ++i) {
		addch(ACS_VLINE);
		for (size_t j = 1; j < 3 + nb_col_left; ++j)
			printw(" ");
		addch(ACS_VLINE);
		for (int j = 4 + nb_col_left; j < COLS - 1; ++j)
			printw(" ");
		addch(ACS_VLINE);
	}
	addch(ACS_LTEE);
	for (size_t j = 1; j < 3 + nb_col_left; ++j)
		addch(ACS_HLINE);
	addch(ACS_BTEE);
	for (int j = 4 + nb_col_left; j < COLS - 1; ++j)
		addch(ACS_HLINE);
	addch(ACS_RTEE);
	for (int i = 0; i < nb_line; ++i) {
		addch(ACS_VLINE);
		for (int j = 1; j < COLS - 1; ++j)
			printw(" ");
		addch(ACS_VLINE);
	}
	addch(ACS_LLCORNER);
	for (int j = 1; j < COLS - 1; ++j)
		addch(ACS_HLINE);
	addch(ACS_LRCORNER);
} /* ui_print_window */

typedef struct  s_tmp_struct_print{
	int    i_actu;
	int    index;
	size_t nb_col_left;
}               t_tmp_struct_print;

static void     ui_print_single_message(char * line, t_tmp_struct_print * stpp) {
	int tot_size;
	size_t len;

	tot_size = COLS - 11 + stpp->nb_col_left;
	len      = (strlen(line) / tot_size) + 1;
	if (stpp->i_actu == 0 || stpp->i_actu <= (int) len)
		return;

	stpp->i_actu -= len;
	for (size_t i = 0; i < len; ++i) {
		move(stpp->i_actu + i, 2);
		if (i == 0)
			printw("%*d", stpp->nb_col_left, stpp->index);
		else
			printw("%*s", stpp->nb_col_left, "");
		move(stpp->i_actu + i, 5 + stpp->nb_col_left);
		printw("%.*s", tot_size, line + i * tot_size);
	}
	stpp->index--;
}

static void     ui_print_messages(t_ui * ui, int nb_line, size_t nb_col_left) {
	t_tmp_struct_print stp;
	size_t i_max = LINES - 2 - nb_line;

	for (size_t i = i_max - 1; i >= 1; --i) {
		move(i, 2);
		for (size_t j = 0; j < nb_col_left; ++j)
			printw("-");
	}
	stp.i_actu      = i_max;
	stp.index       = lst_size(ui->li_messages);
	stp.nb_col_left = nb_col_left;
	lst_iterp(ui->li_messages, (t_iterpf) ui_print_single_message, &stp);
}

static void     ui_print_entry(t_ui * ui, int nb_line, int margin) {
	int len_text;
	char * ptr;

	move(LINES - 1 - nb_line, 2);
	printw("%s: ", ui->pseudo);
	ptr = ui->line;
	while (nb_line) {
		if (nb_line == 1)
			len_text = ui->len % (COLS - margin);
		else
			len_text = (COLS - margin);
		move(LINES - 1 - nb_line, margin - 2);
		printw("%.*s", len_text, ptr);
		ptr += len_text;
		nb_line--;
	}
}

void            ui_ncurses_print(t_ui * ui) {
	int nb_line;
	int margin;
	int nb_col_left;

	margin      = 6 + strlen(ui->pseudo);
	nb_line     = (ui->len / (COLS - margin)) + 1;
	nb_col_left = (int) (ceil(log10(1 + (double) lst_size(ui->li_messages))));

	clear();
	ui_print_window(nb_line, nb_col_left);
	ui_print_messages(ui, nb_line, nb_col_left);
	ui_print_entry(ui, nb_line, margin);
}
