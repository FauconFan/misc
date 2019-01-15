/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:19:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/15 16:28:02 by jpriou           ###   ########.fr       */
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
			{
				ft_printf("SALT = %s\n", cmd->salt);
				ft_printf("KEY  = %s\n", cmd->key);
				if (ft_need_iv(cmd->mode_cipher))
					ft_printf("IV   = %s\n", cmd->vector);
			}
			if (cmd->ask_password == FALSE)
				core(cmd, key, iv);
		}
	}
	ft_ssl_des_free(&cmd);
}
