/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strformat2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:59:07 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 14:30:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char	*ft_strformat2(
			const char *format,
			const char *string1,
			const char *string2)
{
	int			pos[2];
	char		*res;
	size_t		len[3];
	size_t		offset;

	if (format == NULL || string1 == NULL || string2 == NULL
		|| (pos[0] = ft_strcpos(format, '%')) == -1
		|| (pos[1] = ft_strcpos(format + pos[0] + 1, '%')) == -1)
		return (ft_strdup(format));
	pos[1] += pos[0] + 1;
	len[0] = ft_strlen(format);
	len[1] = ft_strlen(string1);
	len[2] = ft_strlen(string2);
	res = ft_strnew(len[0] + len[1] + len[2]);
	ft_strncpy(res, format, (size_t)pos[0]);
	offset = (size_t)pos[0];
	ft_strcpy(res + offset, string1);
	offset += len[1];
	ft_strncpy(res + offset, format + (size_t)pos[0] + 1,
		(size_t)pos[1] - (size_t)pos[0] - 1);
	offset += (size_t)pos[1] - (size_t)pos[0] - 1;
	ft_strcpy(res + offset, string2);
	offset += len[2];
	ft_strcpy(res + offset, format + (size_t)pos[1] + 1);
	return (res);
}
