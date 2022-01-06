/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:59:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 10:53:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_arg_config		g_config_args_base[] =
{
	{'d', NULL, HELP_OPT_DEC, HELP_DEC_TAG, CLI_BOOL, {FALSE}},
	{'e', NULL, HELP_OPT_ENC, HELP_ENC_TAG, CLI_BOOL, {FALSE}},
	{'i', "in", HELP_OPT_IN, HELP_IN_TAG, CLI_STRING, { .str_val = NULL}},
	{'o', "out", HELP_OPT_OUT, HELP_OUT_TAG, CLI_STRING, { .str_val = NULL}},
};

static void				build_base_cmd(
							t_cmd_config_n *cptr,
							char *cmd)
{
	t_cli_config	*cconf;

	if ((cconf = (t_cli_config *)malloc(sizeof(t_cli_config))) == NULL)
		exit(2);
	cptr->cmd = ft_strdup(cmd);
	cptr->help = NULL;
	cptr->cmd_type = CMD_CLI;
	cptr->u.cli_config = cconf;
	cconf->help = ft_strdup(HELP_BASE64);
	cconf->len = sizeof(g_config_args_base) / sizeof(g_config_args_base[0]);
	cconf->args = g_config_args_base;
}

t_cmd_config_n			*ft_ssl_add_base_cmd(t_cmd_config_n *cmds_tab)
{
	build_base_cmd(cmds_tab + 0, CMD_BASE64);
	build_base_cmd(cmds_tab + 1, CMD_BASE64_URL);
	return (cmds_tab + 2);
}
