/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_any.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:10:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 08:35:59 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_str_any(char *s, t_bool (*f)(int c))
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (f(s[index]) != 0)
			return (True);
		index++;
	}
	return (False);
}
