/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:29:35 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/03 16:44:01 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *), void *(*cpy)(void *))
{
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	if (lst != NULL)
	{
		tmp = f(lst);
		res = ft_lstnew(tmp->content, cpy);
		res->next = ft_lstmap(lst->next, f, cpy);
	}
	return (res);
}
