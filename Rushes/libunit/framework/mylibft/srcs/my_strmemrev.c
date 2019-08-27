/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strmemrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:33:51 by dwald             #+#    #+#             */
/*   Updated: 2016/12/15 18:33:56 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

char	*my_strmemrev(const char *s)
{
	char	*rev_dup;
	int		len;
	int		i;

	i = 0;
	len = my_strlen(s);
	if ((rev_dup = my_strnew(len)) == NULL)
		return (NULL);
	while (len >= 0)
		rev_dup[i++] = s[--len];
	return (rev_dup);
}
