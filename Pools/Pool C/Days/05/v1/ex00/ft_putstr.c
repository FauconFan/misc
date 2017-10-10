/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 09:13:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/06 09:31:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		index;
	char	c;

	c = *str;
	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(c);
		index++;
		c = str[index];
	}
}
