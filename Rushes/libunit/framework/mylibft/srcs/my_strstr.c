/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:34:01 by dwald             #+#    #+#             */
/*   Updated: 2016/12/14 12:15:52 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char	*my_strstr(const char *big, const char *little)
{
	if (!*little)
		return ((char*)big);
	while (*big)
	{
		if (my_strnequ(big, little, my_strlen(little)))
			return ((char*)big);
		big++;
	}
	return (NULL);
}
