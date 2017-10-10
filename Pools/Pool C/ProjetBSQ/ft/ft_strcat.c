/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 18:14:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/23 19:15:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src, int rank)
{
	int		index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[rank + index] = src[index];
		index++;
	}
	dest[rank + index] = '\0';
	return (dest);
}
