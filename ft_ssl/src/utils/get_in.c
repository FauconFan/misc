/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:28:14 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/25 09:50:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		*get_in(char *input_file, size_t *len_in)
{
	char	*res;
	char	*errno_str;

	if (input_file == NULL)
		res = ft_get_content_file_fd_nostat(0, len_in, &errno_str);
	else
		res = ft_get_content_file(input_file, len_in, &errno_str);
	if (errno_str != NULL)
		ft_dprintf(2, "Input error: %s\n", errno_str);
	return (res);
}

char		*get_in_ascii(char *input_file, size_t *len_in, t_bool ascii_mode)
{
	char	*res;
	char	*tmp;

	if ((res = get_in(input_file, len_in)) == NULL)
		return (NULL);
	if (ascii_mode)
	{
		tmp = (char *)ft_unbase64(res, len_in);
		ft_strdel(&res);
		res = tmp;
	}
	return (res);
}
