/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_des_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:58:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/21 11:43:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

size_t			g_cmds_des_size = 1;

t_des_config	g_cmds_des[1] =
{
	{"ecb", CMD_ECB, ECB},
};

static t_des_config *get_des_config(t_cmd_parser *parser)
{
	size_t	i;

	i = 0;
	while (i < g_cmds_des_size)
	{
		if (ft_strequ(parser->list_commands[0], g_cmds_des[i].cmd))
			return (g_cmds_des + i);
		i++;
	}
	return NULL;
}

t_bool				is_des_cmd(char *cmd)
{
	size_t	i;

	i = 0;
	while (i < g_cmds_des_size)
	{
		if (ft_strequ(cmd, g_cmds_des[i].cmd))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_des_cmd			*ft_ssl_des_init(t_cmd_parser *parser)
{
	t_des_cmd		*res;
	t_des_config	*config;
	t_bool			encode_mode;
	t_bool			decode_mode;

	encode_mode = ft_cli_getb(parser->parser, HELP_ENC_TAG);
	decode_mode = ft_cli_getb(parser->parser, HELP_DEC_TAG);
	if (encode_mode && decode_mode)
	{
		ft_dprintf(2, "Cannot encode AND decode mode at the same time\n");
		return (NULL);
	}
	config = get_des_config(parser);
	ft_memcheck((res = (t_des_cmd *)malloc(sizeof(t_des_cmd))));
	res->ascii = ft_cli_getb(parser->parser, HELP_ASC_TAG);
	res->mode_cipher = config->mode_cipher;
	res->encode_mode = !ft_cli_getb(parser->parser, HELP_DEC_TAG);
	res->in = ft_cli_gets(parser->parser, HELP_IN_TAG);
	res->out = ft_cli_gets(parser->parser, HELP_OUT_TAG);
	res->key = ft_cli_gets(parser->parser, HELP_KEY_TAG);
	res->ask_password = ft_cli_getb(parser->parser, HELP_PWD);
	res->salt = ft_cli_gets(parser->parser, HELP_SALT_HEX);
	res->vector = ft_cli_gets(parser->parser, HELP_VEC_HEX);
	return res;
}

void				ft_ssl_des_free(t_des_cmd **cmd)
{
	free(*cmd);
	*cmd = NULL;
}
