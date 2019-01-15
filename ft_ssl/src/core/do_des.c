/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:19:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/15 13:25:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_bool	handle_uint64(uint64_t *key, char *str)
{
	size_t	len;
	char	*upper;

	if (str == NULL || ft_str_is_xdigit(str) == FALSE)
		return (FALSE);
	len = ft_strlen(str);
	if (len > 16)
		return (FALSE);
	upper = ft_str_toupper(str);
	*key = ft_atoll_base(upper, BASE_HEXA);
	*key = *key << (4 * (16 - len));
	ft_strdel(&upper);
	return (TRUE);
}

static t_bool	handle_error(
					t_des_cmd *cmd,
					uint64_t *key,
					uint64_t *iv)
{
	if (handle_uint64(key, cmd->key) == FALSE)
	{
		ft_dprintf(2, "You should provide a valid key\n");
		return (FALSE);
	}
	if (ft_need_iv(cmd->mode_cipher) && handle_uint64(iv, cmd->vector) == FALSE)
	{
		ft_dprintf(2, "You should provide a valid initialisation vector (iv)\n");
		return (FALSE);
	}
	return (TRUE);
}

static void	core(t_des_cmd *cmd, uint64_t key, uint64_t iv)
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
		ft_strdel((char **)&content_in);
		ft_strdel((char **)&content_out);
	}
	ft_des_free(&des);
}

void			do_des(t_cmd_parser *parser)
{
	t_des_cmd		*cmd;
	uint64_t		key;
	uint64_t		iv;

	cmd = ft_ssl_des_init(parser);
	if (cmd == NULL)
		return ;
	if (handle_error(cmd, &key, &iv))
	{
		core(cmd, key, iv);
	}
	ft_ssl_des_free(&cmd);
}
