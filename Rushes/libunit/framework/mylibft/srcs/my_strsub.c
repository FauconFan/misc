/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:50:05 by dwald             #+#    #+#             */
/*   Updated: 2017/04/17 12:45:48 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” substring from the string
** given as argument. The substring begins at indexstart and is of size len.
** If start and len aren’t refering to a valid substring, the behavior is
** undefined. If the allocation fails, the function returns NULL
*/

char	*my_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;

	if (s)
	{
		if ((new = my_strnew(len)) == NULL)
			return (NULL);
		while (len--)
			*(new + len) = *(s + len + start);
		return (new);
	}
	return (NULL);
}
