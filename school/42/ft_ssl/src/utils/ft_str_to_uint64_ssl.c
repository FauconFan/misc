/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_uint64_ssl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:35:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/15 15:36:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_bool		ft_str_to_uint64_ssl(uint64_t *key, char *str)
{
	size_t	len;
	char	*upper;

	if (str == NULL || ft_str_is_xdigit(str) == FALSE)
		return (FALSE);
	len = ft_strlen(str);
	if (len > 16)
		return (FALSE);
	upper = ft_str_toupper(str);
	*key = ft_atoll_base(upper, BASE_HEXA);
	*key = *key << (4 * (16 - len));
	ft_strdel(&upper);
	return (TRUE);
}
