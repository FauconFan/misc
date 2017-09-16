/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:58:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:45:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int	index[2];

	index[0] = 0;
	index[1] = 0;
	if (src == 0 || *src == 0)
		return (dest);
	if (dest == 0)
		return (0);
	while (dest[index[0]])
		index[0]++;
	while (src[index[1]])
	{
		dest[index[0] + index[1]] = src[index[1]];
		index[1]++;
	}
	dest[index[0] + index[1]] = 0;
	return (dest);
}