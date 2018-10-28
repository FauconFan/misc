/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:33:08 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/28 14:56:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		set_out(char *output_file, char *o, size_t len_out, t_bool nl)
{
	char	*errno_str;

	if (output_file == NULL)
	{
		write(1, o, len_out);
		if (nl && len_out > 0 && o[len_out - 1] != '\n')
			write(1, "\n", 1);
	}
	else
	{
		ft_put_content_file(output_file, o, len_out, &errno_str);
		if (errno_str != NULL)
		{
			ft_dprintf(2, "Output error: %s\n", errno_str);
		}
	}
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
