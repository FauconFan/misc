/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:58:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/16 22:57:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_arg_config		g_config_args_des[] =
{
	{'a', NULL, HELP_ASC_OUTPUT, HELP_ASC_TAG, CLI_BOOL, {FALSE}},
	{'d', NULL, HELP_OPT_DEC, HELP_DEC_TAG, CLI_BOOL, {FALSE}},
	{'e', NULL, HELP_OPT_ENC, HELP_ENC_TAG, CLI_BOOL, {FALSE}},
	{'i', "in", HELP_OPT_IN, HELP_IN_TAG, CLI_STRING, { .str_val = NULL }},
	{'o', "out", HELP_OPT_OUT, HELP_OUT_TAG, CLI_STRING, { .str_val = NULL }},
	{'k', "key", HELP_KEY_HEX, HELP_KEY_TAG, CLI_STRING, { .str_val = NULL }},
	{'p', "password", HELP_PWD, HELP_PWD_TAG, CLI_STRING, { .str_val = NULL }},
	{0, "ask-pass", HELP_APWD, HELP_APWD_TAG, CLI_BOOL, {FALSE}},
	{'s', "salt", HELP_SALT_HEX, HELP_SALT_TAG, CLI_STRING, { .str_val = NULL }},
	{'v', "iv", HELP_VEC_HEX, HELP_VEC_TAG, CLI_STRING, { .str_val = NULL }},
	{0, "no-pad", HELP_NOPAD, HELP_NOPAD_TAG, CLI_BOOL, {FALSE}},
};

static void				build_des_cmd(
							t_cmd_config_n *cptr,
							t_des_config des_cmd)
{
	t_cli_config	*cconf;

	if ((cconf = (t_cli_config *)malloc(sizeof(t_cli_config))) == NULL)
		exit(2);
	cptr->cmd = ft_strdup(des_cmd.cmd);
	cptr->help = NULL;
	cptr->cmd_type = CMD_CLI;
	cptr->u.cli_config = cconf;
	ft_sprintf(&cconf->help, HELP_DES, des_cmd.help_title);
	cconf->len = sizeof(g_config_args_des) / sizeof(g_config_args_des[0]);
	cconf->args = g_config_args_des;
}

t_cmd_config_n			*ft_ssl_add_des_cmd(t_cmd_config_n *cmds_tab)
{
	size_t		i;

	i = -1;
	while (++i < g_cmds_des_size)
	{
		build_des_cmd(cmds_tab, g_cmds_des[i]);
		++cmds_tab;
	}
	return (cmds_tab);
}
