/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:35:46 by dwald             #+#    #+#             */
/*   Updated: 2016/12/14 23:01:10 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

int		my_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		if (my_strncmp(s1, s2, n) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
