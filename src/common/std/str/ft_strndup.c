/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:12:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 17:24:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*res;

	if (str == NULL)
		return (NULL);
	res = malloc(n + 1);
	if (res == NULL)
		return (NULL);
	ft_strncpy(res, str, n);
	return (res);
}
