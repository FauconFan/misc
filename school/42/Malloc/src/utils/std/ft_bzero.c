/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 08:19:26 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 12:32:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

inline void	ft_bzero(void *v, size_t l)
{
	char	*s;
	size_t	i;

	s = (char *)v;
	i = 0;
	while (i < l)
		s[i++] = 0;
}