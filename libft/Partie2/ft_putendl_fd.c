/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:13:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:46:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *str, int fd)
{
	int		length;

	length = 0;
	if (str == 0)
	{
		ft_putendl_fd("(null)", fd);
		return ;
	}
	while (str[length])
		length++;
	write(fd, str, length);
	write(fd, "\n", 1);
}