/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 18:14:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 15:51:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		begin_index_dest;
	int		index;

	index = 0;
	begin_index_dest = 0;
	while (dest[index] != '\0')
		index++;
	begin_index_dest = index;
	index = 0;
	while (src[index] != '\0')
	{
		dest[begin_index_dest + index] = src[index];
		index++;
	}
	dest[begin_index_dest + index] = '\0';
	return (dest);
}
