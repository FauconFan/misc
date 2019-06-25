/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strformat1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:59:07 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 12:01:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char	*ft_strformat1(const char *format, const char *string)
{
	int			pos;
	char		*res;
	size_t		len[2];

	pos = ft_strcpos(format, '%');
	if (format == NULL || string == NULL || pos == -1)
		return (ft_strdup(format));
	len[0] = ft_strlen(format);
	len[1] = ft_strlen(string);
	res = ft_strnew(len[0] + len[1]);
	ft_strncpy(res, format, (size_t)pos);
	ft_strcpy(res + pos, string);
	ft_strcpy(res + pos + len[1], format + (size_t)pos + 1);
	return (res);
}
