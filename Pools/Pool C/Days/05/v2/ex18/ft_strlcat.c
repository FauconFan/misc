/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 18:40:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 16:09:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *s)
{
	unsigned int		index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	int					beg_i_d;
	int					index;
	unsigned int		length[2];
	unsigned int		res;

	length[0] = str_len(dest);
	length[1] = str_len(src);
	res = (nb < length[0]) ? length[1] + nb : length[1] + length[0];
	beg_i_d = nb - length[0];
	beg_i_d = (beg_i_d < 0) ? 0 : beg_i_d;
	index = 0;
	while (beg_i_d >= 0 && index < beg_i_d - 1 && src[index] != '\0')
	{
		dest[length[0] + index] = src[index];
		index++;
	}
	dest[length[0] + index] = '\0';
	return (res);
}
