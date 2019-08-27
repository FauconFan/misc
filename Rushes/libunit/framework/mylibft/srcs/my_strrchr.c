/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:53:57 by dwald             #+#    #+#             */
/*   Updated: 2016/12/06 10:40:32 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char	*my_strrchr(const char *s, int c)
{
	int len;

	len = my_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char*)s + len);
		--len;
	}
	return (NULL);
}
