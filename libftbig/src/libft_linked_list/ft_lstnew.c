/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:19:44 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 10:08:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content, void *(*cpy)(void *))
{
	t_list	*res;

	MEMCHECK((res = (t_list *)malloc(sizeof(t_list))));
	res->content = cpy(content);
	res->next = 0;
	return (res);
}
