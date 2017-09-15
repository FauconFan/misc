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
 	if (s == 0 || *s == 0)
 	{
 		if (*s == c)
 			return ((char *)s);
 		return (NULL);
 	}
 	if (*s == c)
 		return ((char *)s);
 	return (ft_strchr(s + 1, c));
 }