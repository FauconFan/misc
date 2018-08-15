/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dgst_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:58:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/15 12:01:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

size_t			g_cmds_dgst_size = 9;

t_dgst_config	g_cmds_dgst[9] = {
				{"md5",			CMD_MD5,		&ft_md5,		"MD5"},
				{"md4",			CMD_MD4,		&ft_md4,		"MD4"},
				{"sha1",		CMD_SHA1,		&ft_sha1,		"SHA1"},
				{"sha224",		CMD_SHA224,		&ft_sha224,		"SHA224"},
				{"sha256",		CMD_SHA256,		&ft_sha256,		"SHA256"},
				{"sha384",		CMD_SHA384,		&ft_sha384,		"SHA384"},
				{"sha512",		CMD_SHA512,		&ft_sha512,		"SHA512"},
				{"sha512/256",	CMD_SHA512_256,	&ft_sha512_256,	"SHA512/256"},
				{"sha512/224",	CMD_SHA512_224,	&ft_sha512_224,	"SHA512/224"}};

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
	return NULL;
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
	return res;
}

void			ft_ssl_dgst_free(t_dgst_cmd **cmd)
{
	free(*cmd);
	*cmd = NULL;
}
