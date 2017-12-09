/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:12:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/09 17:39:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		merge_next(
		t_list *actu,
		void *data,
		int (*cmp)(void *d1, void *d2),
		void *(*cpy)(void *data))
{
	t_list	*tmp;

	if (actu->next == 0)
		actu->next = ft_lstnew(data, cpy);
	else
	{
		if (cmp(actu->next->content, data) > 0)
		{
			tmp = actu->next;
			actu->next = ft_lstnew(data, cpy);
			actu->next->next = tmp;
		}
		else
			merge_next(actu->next, data, cmp, cpy);
	}
}

void			ft_lstmerge(
		t_list **head,
		void *data,
		int (*cmp)(void *d1, void *d2),
		void *(*cpy)(void *data))
{
	t_list	*tmp;

	if (head == 0)
		return ;
	if (*head == 0)
		*head = ft_lstnew(data, cpy);
	else
	{
		if (cmp((*head)->content, data) > 0)
		{
			tmp = *head;
			*head = ft_lstnew(data, cpy);
			(*head)->next = tmp;
		}
		else
		{
			merge_next(*head, data, cmp, cpy);
		}
	}
}
