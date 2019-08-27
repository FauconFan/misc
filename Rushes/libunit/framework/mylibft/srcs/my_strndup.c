/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:32:58 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 17:25:54 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char		*my_strndup(const char *s1, int n)
{
	char	*dup;
	int		i;

	i = 0;
	if ((dup = (char*)malloc(sizeof(char) * (n + 1))) == NULL)
		my_protect_malloc();
	while (s1[i] != '\0' && n != 0)
	{
		dup[i] = s1[i];
		i++;
		n--;
	}
	dup[i] = '\0';
	return (dup);
}
