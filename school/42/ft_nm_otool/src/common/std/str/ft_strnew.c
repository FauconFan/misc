/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:00:58 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 11:03:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char	*ft_strnew(size_t len)
{
	char	*res;

	if ((res = malloc(len + 1)) == NULL)
		return (NULL);
	ft_bzero(res, len + 1);
	return (res);
}
