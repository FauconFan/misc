/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syms_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:41:33 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 19:06:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_sym	*ft_syms_new(size_t nmemb)
{
	t_sym	*symbols;
	size_t	tot_len;

	tot_len = sizeof(t_sym) * nmemb;
	if ((symbols = malloc(tot_len)) == NULL)
		return (NULL);
	ft_bzero(symbols, tot_len);
	return (symbols);
}
