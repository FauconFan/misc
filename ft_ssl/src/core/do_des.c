/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:19:18 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/21 11:44:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		do_des(t_cmd_parser *parser)
{
	t_des_cmd	*cmd;

	cmd = ft_ssl_des_init(parser);
	if (cmd == NULL)
		return ;
	ft_printf("ascii %d\n", cmd->ascii);
	ft_printf("mode_cipher %d\n", cmd->mode_cipher);
	ft_printf("encode mode %d\n", cmd->encode_mode);
	ft_printf("in %s\n", cmd->in);
	ft_printf("out %s\n", cmd->out);
	ft_printf("key %s\n", cmd->key);
	ft_printf("key_b %d\n", cmd->ask_password);
	ft_printf("salt %s\n", cmd->salt);
	ft_printf("vector %s\n", cmd->vector);
	ft_ssl_des_free(&cmd);
}
