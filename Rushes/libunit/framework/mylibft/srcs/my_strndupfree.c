/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strndupfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:32:58 by dwald             #+#    #+#             */
/*   Updated: 2017/09/15 15:22:40 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char		*my_strndupfree(char *s1, int n, int free_malloc)
{
	char	*dup;
	int		i;

	i = 0;
	if ((dup = (char*)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	while (s1[i] != '\0' && n != 0)
	{
		dup[i] = s1[i];
		i++;
		n--;
	}
	dup[i] = '\0';
	if (free_malloc != 0)
		my_strdel(&s1);
	return (dup);
}
