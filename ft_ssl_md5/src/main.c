/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:24:31 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 15:42:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int					main(int argc, char **argv) {
	t_cmd_builder_parser	*bd_parser;
	t_cmd_parser			*parser;
	t_opt_error				err;

	bd_parser = ft_create_cmd_builder_parser(&argc, &argv, HELP_PROG);
	ft_add_cmd_u(bd_parser, build_md5_cmd());
	parser = ft_run_cmd(&bd_parser, &err);
	if (has_printed_help(err) == FALSE)
	{
		ft_putendl("YES");
	}
	ft_free_cmd_parser(&parser);
    return 0;
}
