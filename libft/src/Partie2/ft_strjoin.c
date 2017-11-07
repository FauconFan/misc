/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:22:47 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/07 14:47:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*res;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	if ((res = (char *)malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
	{
		res[len1] = s1[len1++];
	}
	while (s2[len2])
	{
		res[len1 + len2] = s2[len2];
		len2++;
	}
	res[len1 + len2] = 0;
	return (res);
}
