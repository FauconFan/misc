/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:34:49 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/04 14:32:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	c;
	int		length;
	int		index;

	length = 0;
	c = str[0];
	while (c != '\0')
	{
		length++;
		c = str[length];
	}
	index = 0;
	while (index != length / 2)
	{
		c = str[index];
		str[index] = str[length - 1 - index];
		str[length - 1 - index] = c;
		index++;
	}
	return (str);
}
