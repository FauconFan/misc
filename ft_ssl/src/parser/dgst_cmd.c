/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dgst_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:58:06 by jpriou            #+#    #+#             */
/*   Updated: 2018/09/20 12:01:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_cmd_builder_parser_n	*build_msg_digest_cmd(char *title, char *cmd)
{
	t_cli_builder_parser	*cli;
	char					*helper;

	ft_sprintf(&helper, HELP_DGT, title);
	cli = ft_create_cli_builder(helper);
	ft_strdel(&helper);
	ft_cli_add_u(cli,
				ft_create_s_opt('p', HELP_OPT_P),
				ft_create_bool_arg(HELP_STDIN_TAG, FALSE));
	ft_cli_add_u(cli,
				ft_create_s_opt('q', HELP_OPT_Q),
				ft_create_bool_arg(HELP_QUIET_TAG, FALSE));
	ft_cli_add_u(cli,
				ft_create_s_opt('r', HELP_OPT_R),
				ft_create_bool_arg(HELP_REV_TAG, FALSE));
	ft_cli_add_u(cli,
				ft_create_s_opt('s', HELP_OPT_S),
				ft_create_array_arg(HELP_SAM_TAG));
	return (ft_create_cmd_builder_parser_node_cli(cmd, &cli));
}

void							ft_ssl_add_dgst_cmd(t_cmd_builder_parser *bd_parser)
{
	size_t		i;

	i = 0;
	while (i < g_cmds_dgst_size)
	{
		ft_add_cmd_u(bd_parser,
			build_msg_digest_cmd(g_cmds_dgst[i].help_title, g_cmds_dgst[i].cmd));
		i++;
	}
}
