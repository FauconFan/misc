/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:59:55 by jpriou            #+#    #+#             */
/*   Updated: 2018/09/20 12:01:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_cmd_builder_parser_n	*build_base64_cmd(char *cmd)
{
	t_cli_builder_parser	*cli;

	cli = ft_create_cli_builder(HELP_BASE64);
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
	return (ft_create_cmd_builder_parser_node_cli(cmd, &cli));
}

void							ft_ssl_add_base_cmd(t_cmd_builder_parser *bd_parser)
{
	ft_add_cmd_u(bd_parser, build_base64_cmd(CMD_BASE64));
	ft_add_cmd_u(bd_parser, build_base64_cmd(CMD_BASE64_URL));
}
