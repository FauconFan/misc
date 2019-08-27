/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:12:58 by dwald             #+#    #+#             */
/*   Updated: 2016/12/13 19:32:14 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char	*my_strnstr(const char *big, const char *little, size_t n)
{
	if (!*little)
		return ((char*)big);
	while (*big && n >= my_strlen(little))
	{
		if (my_strnequ(little, big, my_strlen(little)) == 1)
			return ((char*)big);
		big++;
		n--;
	}
	return (NULL);
}
