/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dgst_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:58:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 10:45:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_arg_config		g_config_args_dgst[] =
{
	{'p', NULL, HELP_OPT_P, HELP_STDIN_TAG, CLI_BOOL, {FALSE}},
	{'q', NULL, HELP_OPT_Q, HELP_QUIET_TAG, CLI_BOOL, {FALSE}},
	{'r', NULL, HELP_OPT_R, HELP_REV_TAG, CLI_BOOL, {FALSE}},
	{'s', NULL, HELP_OPT_S, HELP_SAM_TAG, CLI_ARRAY, {FALSE}},
};

static void				build_dgst_cmd(
							t_cmd_config_n *cptr,
							t_dgst_config dgst_cmd)
{
	t_cli_config	*cconf;

	if ((cconf = (t_cli_config *)malloc(sizeof(t_cli_config))) == NULL)
		exit(2);
	cptr->cmd = ft_strdup(dgst_cmd.cmd);
	cptr->help = NULL;
	cptr->cmd_type = CMD_CLI;
	cptr->u.cli_config = cconf;
	ft_sprintf(&cconf->help, HELP_DGT, dgst_cmd.help_title);
	cconf->len = sizeof(g_config_args_dgst) / sizeof(g_config_args_dgst[0]);
	cconf->args = g_config_args_dgst;
}

t_cmd_config_n			*ft_ssl_add_dgst_cmd(t_cmd_config_n *cmds_tab)
{
	size_t		i;

	i = -1;
	while (++i < g_cmds_dgst_size)
	{
		build_dgst_cmd(cmds_tab, g_cmds_dgst[i]);
		++cmds_tab;
	}
	return (cmds_tab);
}
