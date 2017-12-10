/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:19:44 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/10 13:58:37 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content, void *(*cpy)(void *))
{
	return (ft_lstnew_nocpy(cpy(content)));
}

t_list			*ft_lstnew_nocpy(void *content)
{
	t_list	*res;

	ft_memcheck((res = (t_list *)malloc(sizeof(t_list))));
	res->content = content;
	res->next = 0;
	return (res);
}