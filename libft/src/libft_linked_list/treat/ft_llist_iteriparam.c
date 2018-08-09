/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_iteriparam.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:31:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_iteriparam(
					t_llist *lst,
					void *param,
					void (*f)(void *, void *, size_t))
{
	t_llist_elem	*actu;
	size_t			i;

	actu = lst->datas;
	i = 0;
	while (actu)
	{
		f(actu->content, param, i);
		actu = actu->next;
		i++;
	}
}
