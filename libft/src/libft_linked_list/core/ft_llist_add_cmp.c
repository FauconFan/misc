/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_add_cmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:38:52 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:05:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_llist_add_cmp(
									t_llist *lst,
									int (*cmp_f)(void *, void *))
{
	lst->cmp = cmp_f;
}
