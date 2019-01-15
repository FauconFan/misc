/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_des2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:53:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/15 14:53:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		core(t_des_cmd *cmd, uint64_t key, uint64_t iv)
{
	uint8_t			*content_in;
	uint8_t			*content_out;
	size_t			l_in;
	size_t			l_out;
	t_des			*des;
	t_enc_action	action;

	action = (cmd->encode_mode) ? ENCRYPT : DECRYPT;
	des = ft_des_new(key, iv, action, cmd->mode_cipher);
	content_in = (uint8_t *)get_in_ascii(cmd->in, &l_in, (action == DECRYPT) && cmd->ascii);
	if (content_in)
	{
		content_out = ft_des_process(des, content_in, l_in, &l_out);
		prepare_out_ascii(&content_out, &l_out, (action == ENCRYPT && cmd->ascii));
		set_out(cmd->out, (char *)content_out, l_out, (action == ENCRYPT) && cmd->ascii);
		free(content_in);
		free(content_out);
	}
	ft_des_free(&des);
}
