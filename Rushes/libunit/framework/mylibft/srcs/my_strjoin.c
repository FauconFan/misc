/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:11:48 by dwald             #+#    #+#             */
/*   Updated: 2016/12/08 16:04:30 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char	*my_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	if (s1 && s2)
	{
		len = my_strlen(s1) + my_strlen(s2);
		if ((new = my_strnew(len)) == NULL)
			return (NULL);
		my_bzero(new, len);
		new = my_strcat(new, s1);
		new = my_strcat(new, s2);
		return (new);
	}
	return (NULL);
}
