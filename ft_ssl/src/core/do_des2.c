/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_des2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:53:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 10:49:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		core(t_des_cmd *cmd, uint64_t key, uint64_t iv)
{
	uint8_t			*contents[2];
	size_t			lens[2];
	t_des			*des;
	t_enc_action	action;
	t_bool			do_ascii[2];

	action = (cmd->encode_mode) ? ENCRYPT : DECRYPT;
	des = ft_des_new(key, iv, action, cmd->mode_cipher);
	if (cmd->no_pad)
		ft_des_set_pad(des, FALSE);
	do_ascii[0] = action == DECRYPT && cmd->ascii;
	do_ascii[1] = action == ENCRYPT && cmd->ascii;
	contents[0] = (uint8_t *)get_in_ascii(cmd->in, lens + 0, do_ascii[0]);
	if (contents[0])
	{
		contents[1] = ft_des_process(des, contents[0], lens[0], lens + 1);
		prepare_out_ascii(&contents[1], lens + 1, do_ascii[1]);
		set_out(cmd->out, (char *)contents[1], lens[1], do_ascii[1]);
		free(contents[0]);
		free(contents[1]);
	}
	ft_des_free(&des);
}
