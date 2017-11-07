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

<<<<<<< HEAD
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
=======
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
>>>>>>> 2a098b5b5d985b9368218f676957b37709fcc1be
