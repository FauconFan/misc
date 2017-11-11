/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:19:44 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:51:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*content_null(void)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res->content = NULL;
	res->content_size = 0;
	res->next = NULL;
	return (res);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;
	char	*con;
	size_t	index;

	index = 0;
	if (content == NULL)
		return (content_null());
	con = (char *)malloc(sizeof(char) * content_size);
	if (con == NULL)
		return (NULL);
	while (index < content_size)
	{
		con[index] = (char)(((char *)content)[index]);
		index++;
	}
	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res->content = (void *)con;
	res->content_size = content_size;
	res->next = NULL;
	return (res);
}
