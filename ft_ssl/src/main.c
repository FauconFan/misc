/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:24:31 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 10:46:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int					main(int argc, char **argv)
{
	t_cmd_config			*conf;
	t_cmd_parser			*parser;
	t_opt_error				err;

	conf = cmd_config_init();
	parser = ft_getopt_cmd(conf, &argc, &argv, &err);
	cmd_config_end(conf);
	if (has_printed_help(err) == FALSE)
	{
		if (is_dgst_cmd(parser->list_commands[0]))
			do_dgst(parser);
		else if (is_base_cmd(parser->list_commands[0]))
			do_base(parser, parser->list_commands[0]);
		else if (is_des_cmd(parser->list_commands[0]))
			do_des(parser);
	}
	ft_free_cmd_parser(&parser);
	return (0);
}
