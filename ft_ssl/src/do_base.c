/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:28:46 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 17:40:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static char		*get_in(char *input_file)
{
	char	*res;
	char	*errno_str;

	if (input_file == NULL)
		res = ft_get_content_file_fd_nostat(0, &errno_str);
	else
		res = ft_get_content_file(input_file, &errno_str);
	if (errno_str != NULL)
		ft_dprintf(2, "Input error: %s\n", errno_str);
	return (res);
}

static void		set_out(char *output_file, char *o)
{
	char	*errno_str;

	if (output_file == NULL)
	{
		ft_putendl(o);
	}
	else
	{
		ft_put_content_file(output_file, o, &errno_str);
		if (errno_str != NULL)
		{
			ft_dprintf(2, "Output error: %s\n", errno_str);
		}
	}
}

void			do_base(
						t_cmd_parser *parser,
						char *(*f)(uint8_t *, size_t),
						uint8_t *(*unf)(char *, size_t *))
{
	t_bool		encode_flag;
	t_bool		decode_flag;
	char		*content_in;
	char		*content_out;
	size_t		len;

	encode_flag = ft_cli_getb(parser->parser, HELP_ENC_TAG);
	decode_flag = ft_cli_getb(parser->parser, HELP_DEC_TAG);
	if (decode_flag && encode_flag)
		ft_dprintf(2, "You cannot use -e -d flag at the same time\n");
	else
	{
		if ((content_in = get_in(ft_cli_gets(parser->parser, HELP_IN_TAG))))
		{
			if (decode_flag == FALSE)
			{
				content_out = f((uint8_t *)content_in, ft_strlen(content_in));
			}
			else
				content_out = (char *)unf(content_in, &len);
			set_out(ft_cli_gets(parser->parser, HELP_OUT_TAG), content_out);
			ft_strdel(&content_in);
			ft_strdel(&content_out);
		}
	}
}
