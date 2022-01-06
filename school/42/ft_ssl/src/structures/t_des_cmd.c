/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_des_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:58:02 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 11:19:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_des_config	*get_des_config(t_cmd_parser *parser)
{
	size_t	i;

	i = 0;
	while (i < g_cmds_des_size)
	{
		if (ft_strequ(parser->list_commands[0], g_cmds_des[i].cmd))
			return (g_cmds_des + i);
		i++;
	}
	return (NULL);
}

static char			*alloc_if_necessary(char *in)
{
	if (in == NULL)
		return (NULL);
	return (ft_strdup(in));
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

t_des_cmd			*ft_ssl_des_init(t_cmd_parser *par)
{
	t_des_cmd		*res;
	t_des_config	*config;

	if (ft_cli_getb(par->parser, HELP_ENC_TAG) &&
		ft_cli_getb(par->parser, HELP_DEC_TAG))
	{
		ft_dprintf(2, "Cannot encode AND decode mode at the same time\n");
		return (NULL);
	}
	config = get_des_config(par);
	ft_memcheck((res = (t_des_cmd *)malloc(sizeof(t_des_cmd))));
	res->ascii = ft_cli_getb(par->parser, HELP_ASC_TAG);
	res->mode_cipher = config->mode_cipher;
	res->encode_mode = !ft_cli_getb(par->parser, HELP_DEC_TAG);
	res->in = ft_cli_gets(par->parser, HELP_IN_TAG);
	res->out = ft_cli_gets(par->parser, HELP_OUT_TAG);
	res->key = alloc_if_necessary(ft_cli_gets(par->parser, HELP_KEY_TAG));
	res->ask_password = ft_cli_getb(par->parser, HELP_APWD_TAG);
	res->password = alloc_if_necessary(ft_cli_gets(par->parser, HELP_PWD_TAG));
	res->salt = alloc_if_necessary(ft_cli_gets(par->parser, HELP_SALT_TAG));
	res->vector = alloc_if_necessary(ft_cli_gets(par->parser, HELP_VEC_TAG));
	res->no_pad = ft_cli_getb(par->parser, HELP_NOPAD_TAG);
	return (res);
}

void				ft_ssl_des_free(t_des_cmd **cmd)
{
	if ((*cmd)->key)
		free((*cmd)->key);
	if ((*cmd)->salt)
		free((*cmd)->salt);
	if ((*cmd)->vector)
		free((*cmd)->vector);
	if ((*cmd)->password)
		free((*cmd)->password);
	free(*cmd);
	*cmd = NULL;
}
