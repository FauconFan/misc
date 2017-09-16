/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat_n_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 12:05:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/16 13:02:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strconcat_n_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	free(s1);
	free(s2);
	return (res);
}