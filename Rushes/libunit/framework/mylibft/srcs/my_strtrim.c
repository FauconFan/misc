/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:40:46 by dwald             #+#    #+#             */
/*   Updated: 2016/12/14 23:07:36 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char	*my_strtrim(char const *s)
{
	char		*new;
	size_t		i;
	size_t		len;

	i = 0;
	if (s)
	{
		len = my_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == len + 1)
			return (my_strnew(0));
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			len--;
		len = len + 1 - i;
		if ((new = my_strsub(s, i, len)) == NULL)
			return (NULL);
		return (new);
	}
	return (0);
}
