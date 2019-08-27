/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:48:59 by dwald             #+#    #+#             */
/*   Updated: 2017/11/16 16:30:17 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

/*
**   The strcat() and strncat() functions append a copy of the null-terminated
**   string s2 to the end of the null-terminated string s1, then add a terminat-
**   ing `\0'.  The string s1 must have sufficient space to hold the result.
**
**   The strncat() function appends not more than n characters from s2, and then
**   adds a terminating `\0'.
*/

char	*my_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	j = 0;
	i = my_strlen(s1);
	while (s2[j] != '\0' && j < n)
	{
		s1[i++] = s2[j];
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
