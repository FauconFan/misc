/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:33:08 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 17:29:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void is_nl(char *o, size_t len_out, char **tmp_o, size_t *len_tmp)
{
	size_t	i;
	size_t	j;

	*len_tmp = len_out + ((len_out - 1) / PAD_PRINT_ASCII) + 1;
	*tmp_o = ft_strnew(*len_tmp);
	i = 0;
	j = 0;
	while (i < len_out)
	{
		if (i != 0 && i % PAD_PRINT_ASCII == 0)
		{
			(*tmp_o)[j] = '\n';
			++j;
		}
		(*tmp_o)[j] = o[i];
		++i;
		++j;
	}
	if (o[i - 1] == '\n')
		*len_tmp = *len_tmp - 1;
	else
		(*tmp_o)[j] = '\n';
}

void		set_out(char *output_file, char *o, size_t len_out, t_bool nl)
{
	char	*errno_str;
	char	*tmp_o;
	size_t	len_tmp;

	if (nl && len_out != 0)
		is_nl(o, len_out, &tmp_o, &len_tmp);
	else
	{
		tmp_o = o;
		len_tmp = len_out;
	}
	if (output_file == NULL)
		write(1, tmp_o, len_tmp);
	else
	{
		ft_put_content_file(output_file, tmp_o, len_tmp, &errno_str);
		if (errno_str != NULL)
		{
			ft_dprintf(2, "Output error: %s\n", errno_str);
		}
	}
	if (nl)
		free(tmp_o);
}

void		prepare_out_ascii(uint8_t **out, size_t *len, t_bool ascii_mode)
{
	char	*tmp;

	if (ascii_mode)
	{
		tmp = ft_base64((*out), *len);
		*len = ft_strlen(tmp);
		ft_strdel((char **)out);
		*out = (uint8_t *)tmp;
	}
}
