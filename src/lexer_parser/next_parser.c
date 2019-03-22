#include "cimp.h"

//flex
extern t_li_token * scan_string(const char * str);

static t_bool   run_parser_with_config(t_cmd * cmd, t_li_token * li_toks,
  const t_cmd_config * cmd_cf);
static const t_cmd_config * get_conf_cmd(char * cmd);
static char * eat_cmd(t_li_token * li_token);

t_cmd * next_parser(char * line) {
	t_li_token * li_toks;
	t_cmd * res;
	t_bool ok;

	res     = NULL;
	ok      = FALSE;
	li_toks = scan_string(line);
	if (li_toks) {
		li_token_print(li_toks);

		if (li_token_empty(li_toks) == FALSE && li_toks->ok == TRUE) {
			res      = cmd_alloc();
			res->cmd = eat_cmd(li_toks);
			if (res->cmd == NULL)
				ok = FALSE;
			else
				ok = run_parser_with_config(res, li_toks, get_conf_cmd(res->cmd));
		}

		li_token_free(li_toks);
	}
	if (ok == FALSE && res != NULL) {
		cmd_free(res);
		res = NULL;
	}
	return (res);
}

static t_bool   run_parser_with_config(t_cmd * cmd, t_li_token * li_toks,
  const t_cmd_config * cmd_cf) {
	uint8_t opts;
	uint8_t opts_opt;

	if (cmd_cf == NULL)
		return (FALSE);

	opts     = cmd_cf->opts;
	opts_opt = cmd_cf->opts_opt;
	// Some busy stuff to assimilate things
	(void) opts;
	(void) opts_opt;
	(void) cmd;
	(void) li_toks;
	return (TRUE);
}

static const t_cmd_config * get_conf_cmd(char * cmd) {
	for (int i = 0; i < (int) g_command_list_size; i++) {
		if (strcmp(cmd, g_command_list[i].name) == 0) {
			return g_command_list + i;
		}
	}
	return NULL;
}

static char * eat_cmd(t_li_token * li_token) {
	t_token * first;

	first = li_token_get_next(li_token);
	if (first->type != WORD)
		return (NULL);

	return (dupstr(first->u.str));
}
