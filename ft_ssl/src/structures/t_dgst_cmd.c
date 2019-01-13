/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dgst_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:58:02 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 11:39:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_dgst_config *get_dgst_config(t_cmd_parser *parser)
{
	size_t	i;

	i = 0;
	while (i < g_cmds_dgst_size)
	{
		if (ft_strequ(parser->list_commands[0], g_cmds_dgst[i].cmd))
			return (g_cmds_dgst + i);
		i++;
	}
	return (NULL);
}

t_bool				is_dgst_cmd(char *cmd)
{
	size_t	i;

	i = 0;
	while (i < g_cmds_dgst_size)
	{
		if (ft_strequ(cmd, g_cmds_dgst[i].cmd))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_dgst_cmd			*ft_ssl_dgst_init(t_cmd_parser *parser)
{
	t_dgst_cmd		*res;
	t_dgst_config	*config;

	config = get_dgst_config(parser);
	ft_memcheck((res = (t_dgst_cmd *)malloc(sizeof(t_dgst_cmd))));
	res->stdin = ft_cli_getb(parser->parser, HELP_STDIN_TAG);
	res->quiet = ft_cli_getb(parser->parser, HELP_QUIET_TAG);
	res->reverse = ft_cli_getb(parser->parser, HELP_REV_TAG);
	res->samples = ft_cli_geta(parser->parser, HELP_SAM_TAG);
	res->hash = config->hash;
	res->nb_files = parser->parser->argc;
	res->file_names = parser->parser->argv;
	res->name = config->name;
	return (res);
}

void			ft_ssl_dgst_free(t_dgst_cmd **cmd)
{
	free(*cmd);
	*cmd = NULL;
}
