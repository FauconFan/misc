/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:19:18 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/28 14:58:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_bool	handle_uint64(uint64_t *key, char *str)
{
	size_t	len;

	if (str == NULL || ft_str_is_xdigit(str) == FALSE)
		return (FALSE);
	len = ft_strlen(str);
	if (len > 16)
		return (FALSE);
	*key = ft_atoll_base(str, BASE_HEXA);
	*key = *key << (4 * (16 - len));
	return (TRUE);
}

static t_bool	handle_error(
					t_des_cmd *cmd,
					uint64_t *key)
{
	if (handle_uint64(key, cmd->key) == FALSE)
	{
		ft_dprintf(2, "You should provide a valid key\n");
		return (FALSE);
	}
	return (TRUE);
}

static void	core(t_des_cmd *cmd, uint64_t key)
{
	uint8_t			*content_in;
	uint8_t			*content_out;
	size_t			l_in;
	size_t			l_out;
	t_des			*des;
	t_enc_action	action;

	action = (cmd->encode_mode) ? ENCRYPT : DECRYPT;
	des = ft_des_new(key, 0, action, cmd->mode_cipher);
	content_in = (uint8_t *)get_in_ascii(cmd->in, &l_in, (action == DECRYPT) && cmd->ascii);
	if (content_in)
	{
		content_out = ft_des_process(des, content_in, l_in, &l_out);
		prepare_out_ascii(&content_out, &l_out, (action == ENCRYPT && cmd->ascii));
		set_out(cmd->out, (char *)content_out, l_out, FALSE);
		ft_strdel((char **)&content_in);
		ft_strdel((char **)&content_out);
	}
	ft_des_free(&des);
}

void			do_des(t_cmd_parser *parser)
{
	t_des_cmd		*cmd;
	uint64_t		key;
	// uint64_t		iv;

	cmd = ft_ssl_des_init(parser);
	if (cmd == NULL)
		return ;
	if (handle_error(cmd, &key))
	{
		// ft_printf("%llx\n", key);
		core(cmd, key);
		// ft_printf("ascii %d\n", cmd->ascii);
		// ft_printf("mode_cipher %d\n", cmd->mode_cipher);
		// ft_printf("encode mode %d\n", cmd->encode_mode);
		// ft_printf("in %s\n", cmd->in);
		// ft_printf("out %s\n", cmd->out);
		// ft_printf("key %s\n", cmd->key);
		// ft_printf("key_b %d\n", cmd->ask_password);
		// ft_printf("salt %s\n", cmd->salt);
		// ft_printf("vector %s\n", cmd->vector);

	}
	ft_ssl_des_free(&cmd);
}
