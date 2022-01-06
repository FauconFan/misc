/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:58:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:52:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*res;

	len = 0;
	res = 0;
	while (s[len])
		len++;
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	len = 0;
	while (s[len])
	{
		res[len] = s[len];
		len++;
	}
	res[len] = 0;
	return (res);
}
