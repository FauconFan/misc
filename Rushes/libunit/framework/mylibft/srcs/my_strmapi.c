/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:10:54 by dwald             #+#    #+#             */
/*   Updated: 2016/12/07 16:24:00 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char	*my_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	if (s && f)
	{
		len = my_strlen(s);
		if ((temp = my_strnew(len)) == NULL)
			return (NULL);
		else
			while (*s)
				*temp++ = (*f)(i++, *s++);
		return (temp - len);
	}
	return (NULL);
}
