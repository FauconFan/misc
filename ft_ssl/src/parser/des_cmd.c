/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:58:06 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/18 12:42:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void						add_default_opt(t_cli_builder_parser *cli)
{
	ft_cli_add_u(cli,
				ft_create_s_opt('a', HELP_ASC_OUTPUT),
				ft_create_bool_arg(HELP_ASC_TAG, FALSE));
	ft_cli_add_u(cli,
				ft_create_s_opt('d', HELP_OPT_DEC),
				ft_create_bool_arg(HELP_DEC_TAG, FALSE));
	ft_cli_add_u(cli,
				ft_create_s_opt('e', HELP_OPT_ENC),
				ft_create_bool_arg(HELP_ENC_TAG, FALSE));
	ft_cli_add_u(cli,
				ft_create_sl_opt('i', "in", HELP_OPT_IN),
				ft_create_string_arg(HELP_IN_TAG, NULL));
	ft_cli_add_u(cli,
				ft_create_sl_opt('o', "out", HELP_OPT_OUT),
				ft_create_string_arg(HELP_OUT_TAG, NULL));
}

static void						add_advanced_opt(t_cli_builder_parser *cli)
{
	ft_cli_add_u(cli,
				ft_create_sl_opt('k', "key", HELP_KEY_HEX),
				ft_create_string_arg(HELP_KEY_TAG, NULL));
	ft_cli_add_u(cli,
				ft_create_sl_opt('p', "password", HELP_PWD),
				ft_create_bool_arg(HELP_PWD_TAG, FALSE));
	ft_cli_add_u(cli,
				ft_create_sl_opt('s', "salt", HELP_SALT_HEX),
				ft_create_string_arg(HELP_SALT_TAG, NULL));
	ft_cli_add_u(cli,
				ft_create_sl_opt('v', "--iv", HELP_VEC_HEX),
				ft_create_string_arg(HELP_VEC_TAG, NULL));
}

static t_cmd_builder_parser_n	*build_msg_digest_cmd(char *title, char *cmd)
{
	t_cli_builder_parser	*cli;
	char					*helper;

	ft_sprintf(&helper, HELP_DES, title);
	cli = ft_create_cli_builder(helper);
	ft_strdel(&helper);
	add_default_opt(cli);
	add_advanced_opt(cli);
	return (ft_create_cmd_builder_parser_node_cli(cmd, &cli));
}

void							ft_ssl_add_des_cmd(t_cmd_builder_parser *bd_parser)
{
	size_t		i;

	i = 0;
	while (i < g_cmds_des_size)
	{
		ft_add_cmd_u(bd_parser,
			build_msg_digest_cmd(g_cmds_des[i].help_title, g_cmds_des[i].cmd));
		i++;
	}
}
