/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 11:12:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/16 12:07:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strconcat(char *s1, char *s2)
{
	char	*res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}