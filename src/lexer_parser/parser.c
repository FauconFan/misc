#include "cimp.h"

// flex
extern t_li_token * scan_string(const char * str);

static t_bool   run_parser_with_config(t_cmd * cmd, t_li_token * li_toks,
  const t_cmd_config * cmd_cf);
static const t_cmd_config * get_conf_cmd(char * cmd);
static char * eat_cmd(t_li_token * li_token);

t_cmd * parser(char * line) {
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
			if (res->cmd == NULL) {
				printf("La commande entrée n'est pas reconnue...\n");
				ok = FALSE;
			}
			else {
				ok = run_parser_with_config(res, li_toks, get_conf_cmd(res->cmd));
			}
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
	t_token * tok;

	if (cmd_cf == NULL)
		return (FALSE);

	opts     = cmd_cf->opts;
	opts_opt = cmd_cf->opts_opt;
	tok      = NULL;
	while (li_token_empty(li_toks) == FALSE) {
		tok = li_token_get_next(li_toks);
		switch (tok->type) {
			case WORD:
				if (cmd->name != NULL) {
					printf("Have already a name parameter\n");
					return (FALSE);
				}
				if (opts & ARG_NAME || opts & ARG_PATH) {
					cmd->name = dupstr(tok->u.str);
					opts     &= ~(ARG_NAME | ARG_PATH);
				}
				else if (opts_opt & ARG_NAME || opts_opt & ARG_PATH) {
					cmd->name = dupstr(tok->u.str);
					opts_opt &= ~(ARG_NAME | ARG_PATH);
				}
				else {
					printf("No need a name for this command\n");
					return (FALSE);
				}
				break;
			case PATH:
				if (cmd->name != NULL) {
					printf("Have already a path paramecmter\n");
					return (FALSE);
				}
				if (opts & ARG_PATH) {
					cmd->name = dupstr(tok->u.str);
					opts     &= ~(ARG_PATH);
				}
				else if (opts_opt & ARG_PATH) {
					cmd->name = dupstr(tok->u.str);
					opts_opt &= ~(ARG_PATH);
				}
				else {
					printf("No need a path parameter\n");
					return (FALSE);
				}
				break;
			case NUM:
				if (cmd_cf->opts & ARG_NUM && (opts & ARG_NUM) == 0) {
					printf("Have already a num parameter\n");
					return (FALSE);
				}
				else if (opts & ARG_NUM) {
					cmd->num = tok->u.num;
					opts    &= ~(ARG_NUM);
				}
				else if (opts_opt & ARG_NUM) {
					cmd->num  = tok->u.num;
					opts_opt &= ~(ARG_NUM);
				}
				else {
					printf("No need a num parameter\n");
					return (FALSE);
				}
				break;
			case RECT:
				if (cmd_cf->opts & ARG_RECT && (opts & ARG_RECT) == 0) {
					printf("Hav already a rect parameter\n");
					return (FALSE);
				}
				else if (opts & ARG_RECT) {
					cmd->rect = tok->u.rect;
					opts     &= ~(ARG_RECT);
				}
				else if (opts_opt & ARG_RECT) {
					cmd->rect = tok->u.rect;
					opts_opt &= ~(ARG_RECT);
				}
				else {
					printf("No need a rect parameter\n");
					return (FALSE);
				}
				break;
		}
	}
	if (opts != 0) {
		printf("Some arguments are missing\n");
		return (FALSE);
	}
	// Some busy stuff to assimilate things
	return (TRUE);
} /* run_parser_with_config */

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
