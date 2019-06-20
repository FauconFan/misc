/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:11:10 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 17:16:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char	*ft_strdup(const char *str)
{
	size_t	l;
	char	*res;

	if (str == NULL)
		return (NULL);
	l = ft_strlen(str);
	res = malloc(l + 1);
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, str);
	return (res);
}
