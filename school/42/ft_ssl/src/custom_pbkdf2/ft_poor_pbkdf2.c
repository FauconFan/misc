/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poor_pbkdf2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:20:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/15 14:28:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*ft_poor_pbkdf2(char *password, char *salt)
{
	char	*res;
	char	*text;
	size_t	l;

	l = ft_strlen(password);
	text = ft_strnew(l + ft_strlen(salt) / 2);
	ft_strcpy(text, password);
	while (*salt)
	{
		text[l] = (ft_toxdigit(salt[0]) << 4) + ft_toxdigit(salt[1]);
		salt += 2;
		l++;
	}
	res = ft_md5((uint8_t *)text, l);
	free(text);
	return (res);
}
