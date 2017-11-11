/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 09:47:26 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/08 15:40:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (s == 0 || f == 0)
		return ;
	index = 0;
	while (*s)
	{
		f(index, s);
		index++;
		s++;
	}
}
