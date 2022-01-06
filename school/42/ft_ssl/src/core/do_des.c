/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:19:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/16 21:57:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_bool	handle_error(
					t_des_cmd *cmd,
					uint64_t *key,
					uint64_t *iv)
{
	if (ft_str_to_uint64_ssl(key, cmd->key) == FALSE)
	{
		ft_dprintf(2, MSG_VALID_KEY "\n");
		return (FALSE);
	}
	if (ft_need_iv(cmd->mode_cipher) &&
		ft_str_to_uint64_ssl(iv, cmd->vector) == FALSE)
	{
		ft_dprintf(2, MSG_VALID_IV "\n");
		return (FALSE);
	}
	return (TRUE);
}

static void		print_metadata(t_des_cmd *cmd)
{
	char	*tmp[3];

	tmp[0] = ft_str_toupper(cmd->salt);
	tmp[1] = ft_str_toupper(cmd->key);
	tmp[2] = ft_str_toupper(cmd->vector);
	ft_printf("SALT = %s\n", tmp[0]);
	ft_printf("KEY  = %s\n", tmp[1]);
	if (ft_need_iv(cmd->mode_cipher))
		ft_printf("IV   = %s\n", tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
}

void			do_des(t_cmd_parser *parser)
{
	t_des_cmd		*cmd;
	uint64_t		key;
	uint64_t		iv;
	t_bool			running;
	t_bool			need_key;

	running = TRUE;
	cmd = ft_ssl_des_init(parser);
	if (cmd == NULL)
		return ;
	need_key = cmd->ask_password || cmd->key == NULL ||
				(cmd->vector == NULL && ft_need_iv(cmd->mode_cipher));
	if (need_key)
		running = (ask_key_iv(cmd) == 0);
	if (running)
	{
		if (handle_error(cmd, &key, &iv))
		{
			if (need_key)
				print_metadata(cmd);
			if (cmd->ask_password == FALSE)
				core(cmd, key, iv);
		}
	}
	ft_ssl_des_free(&cmd);
}
