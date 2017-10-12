/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 21:57:41 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:45:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

 char	*ft_strchr(const char *s, int c)
 {
 	if (s == NULL)
 		return (NULL);
 	while (*s)
 	{
 		if (*s == c)
 			return ((char *)s);
 		s++;
 	}
 	if (c == '\0')
 		return ((char *)s);
 	return (NULL);
 }