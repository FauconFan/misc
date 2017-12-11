/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:14:17 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 08:35:40 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_str_all(char *s, t_bool (*f)(int c))
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (f(s[index]) == 0)
			return (False);
		index++;
	}
	return (True);
}
