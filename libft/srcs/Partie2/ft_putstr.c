/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:13:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:47:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char const *str)
{
	int	length;

	length = 0;
	if (str == 0)
	{
		ft_putstr("(null)");
		return ;
	}
	while (str[length])
		length++;
	write(1, str, length);
}