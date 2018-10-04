/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:24:31 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 08:29:55 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int					main(int argc, char **argv) {
	(void)argc;
	(void)argv;

	char *str = custom_pbkdf2("coucou");
	// ft_printf("%016s\n", str);
	ft_strdel(&str);
	// t_cmd_builder_parser	*bd_parser;
	// t_cmd_parser			*parser;
	// t_opt_error				err;
	//
	// bd_parser = ft_create_cmd_builder_parser(&argc, &argv, HELP_PROG);
	// ft_ssl_add_cmds(bd_parser);
	// parser = ft_run_cmd(&bd_parser, &err);
	// if (has_printed_help(err) == FALSE)
	// {
	// 	if (is_dgst_cmd(parser->list_commands[0]))
	// 		do_dgst(parser);
	// 	else if (is_base_cmd(parser->list_commands[0]))
	// 		do_base(parser, parser->list_commands[0]);
	// }
	// ft_free_cmd_parser(&parser);
    return 0;
}
