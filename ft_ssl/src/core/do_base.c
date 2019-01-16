/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:28:46 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/16 00:34:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		do_do_base(
						t_cmd_parser *parser,
						char *(*f)(uint8_t *, size_t),
						uint8_t *(*unf)(char *, size_t *))
{
	t_bool		decode_flag;
	char		*content_in;
	char		*content_out;
	size_t		len;

	decode_flag = ft_cli_getb(parser->parser, HELP_DEC_TAG);
	if (decode_flag && ft_cli_getb(parser->parser, HELP_ENC_TAG))
		ft_dprintf(2, "You cannot use -e -d flag at the same time\n");
	else
	{
		if ((content_in = get_in(ft_cli_gets(parser->parser, HELP_IN_TAG), &len)))
		{
			if (decode_flag == FALSE)
			{
				content_out = f((uint8_t *)content_in, len);
				len = ft_strlen(content_out);
			}
			else
				content_out = (char *)unf(content_in, &len);
			set_out(ft_cli_gets(parser->parser, HELP_OUT_TAG), content_out, len, FALSE);
			ft_strdel(&content_in);
			ft_strdel(&content_out);
		}
	}
}

void			do_base(t_cmd_parser *parser, char *cmd)
{
	if (ft_strequ(cmd, CMD_BASE64))
		do_do_base(parser, ft_base64, ft_unbase64);
	else if (ft_strequ(cmd, CMD_BASE64_URL))
		do_do_base(parser, ft_base64_url, ft_unbase64_url);
}

t_bool			is_base_cmd(char *cmd)
{
	return (ft_strequ(cmd, CMD_BASE64) || ft_strequ(cmd, CMD_BASE64_URL));
}
