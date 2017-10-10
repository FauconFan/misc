/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 08:55:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 16:14:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				str__len(char *s)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	tmp;
	int				begin_index_src;
	int				index;
	int				length[22];

	length[0] = str__len(dest);
	length[1] = str__len(src);
	index = 0;
	if (size == 0)
		return (length[1]);
	tmp = size - 1;
	begin_index_src = ((int)(tmp) < length[1]) ? size - 1 : length[1];
	while (index < begin_index_src && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (length[1]);
}
