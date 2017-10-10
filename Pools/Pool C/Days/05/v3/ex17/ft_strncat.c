/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 18:37:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 15:54:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		begin_index_dest;
	int		index;

	index = 0;
	begin_index_dest = 0;
	while (dest[index] != '\0')
		index++;
	begin_index_dest = index;
	index = 0;
	while (src[index] != '\0' && index < nb)
	{
		dest[begin_index_dest + index] = src[index];
		index++;
	}
	dest[begin_index_dest + index] = '\0';
	return (dest);
}
