/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:29:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 15:38:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_cli_builder_parser		*build_msg_digest_cli(char *helper)
{
	t_cli_builder_parser	*res;

	res = ft_create_cli_builder(helper);
	ft_cli_add_u(res,
				ft_create_s_opt('p', HELP_OPT_P),
				ft_create_bool_arg("stdin", FALSE));
	ft_cli_add_u(res,
				ft_create_s_opt('q', HELP_OPT_Q),
				ft_create_bool_arg("quiet", FALSE));
	ft_cli_add_u(res,
				ft_create_s_opt('r', HELP_OPT_R),
				ft_create_bool_arg("reverse", FALSE));
	ft_cli_add_u(res,
				ft_create_s_opt('s', HELP_OPT_S),
				ft_create_array_arg("samples"));
	return res;
}

t_cmd_builder_parser_n			*build_md5_cmd()
{
	t_cli_builder_parser		*cli;

	cli = build_msg_digest_cli(HELP_MD5);
	return ft_create_cmd_builder_parser_node_cli("md5", &cli);
}
