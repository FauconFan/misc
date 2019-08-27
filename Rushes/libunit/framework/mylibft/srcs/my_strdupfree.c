/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strdupfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:32:58 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 17:23:12 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char		*my_strdupfree(char *s1, int free_malloc)
{
	char	*dup;
	int		i;

	i = 0;
	if ((dup = (char*)malloc(sizeof(char) * my_strlen(s1) + 1)) == NULL)
		my_protect_malloc();
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	if (free_malloc != 0)
		my_strdel(&s1);
	return (dup);
}
