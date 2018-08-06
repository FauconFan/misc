/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:12:04 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 16:35:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *content, void *lst_ptr, void *f_ptr)
{
	t_llist		*lst;
	int			(*cmp_f)(void *d1, void *d2);

	lst = (t_llist *)lst_ptr;
	cmp_f = (int (*)(void *, void *))f_ptr;
	ft_llist_merge_one(lst, lst->cpy(content), cmp_f);
}

void			ft_llist_merge(
					t_llist *lst1,
					t_llist	**lst2,
					int (*cmp_f)(void *d1, void *d2))
{
	ft_llist_iterparam2(*lst2, lst1, cmp_f, f);
	ft_llist_free(lst2);
}
