/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:29:35 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/12 13:48:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	if (lst != NULL)
	{
		tmp = f(lst);
		res = ft_lstnew(tmp->content, tmp->content_size);
		res->next = ft_lstmap(lst->next, f);
	}
	return (res);
}
