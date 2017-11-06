/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:03:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/15 10:33:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcpos(char *s, int c)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
