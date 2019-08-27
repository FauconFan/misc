/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:20:21 by dwald             #+#    #+#             */
/*   Updated: 2017/10/13 15:24:34 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

/*
** Returns string length until end of line or EOF is reached.
*/

static	size_t	find_end_of_line(char *str, int len)
{
	len = -1;
	if (!str)
		return (0);
	while (str[++len] != '\0')
	{
		if (str[len] == '\n')
			return (len + 1);
	}
	return (0);
}

/*
** Searches fo node with corresponding fd stocked in content->size. If node does
** not exists, creates new node.
*/

static	t_list	*get_node(int fd, t_list **node)
{
	t_list	*ptr;

	ptr = *node;
	while (ptr != NULL)
	{
		if (ptr->content_size == (size_t)fd)
			return (ptr);
		ptr = (ptr)->next;
	}
	if (!ptr)
		ptr = my_lstnew("\0", 1);
	ptr->content_size = fd;
	my_lstadd(node, ptr);
	ptr = *node;
	return (ptr);
}

/*
** Copies string to line and the rest is stocked in the likend lists structure.
** p: pointer to the linked lists structure
** l: length
*/

static	void	my_feed_line(t_list **p, char **line, int l)
{
	char	*tmp;

	*line = my_strdup((*p)->content);
	tmp = (*p)->content;
	(*p)->content = ((l > 0) ? my_strdup((*p)->content + l) : my_strdup(""));
	my_strdel(&tmp);
	return ;
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*node = NULL;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_list			*ptr;
	int				len;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	ptr = get_node(fd, &node);
	while (((len = find_end_of_line(ptr->content, fd))
	|| (ret = read(fd, buff, BUFF_SIZE)) > 0) && len <= 0)
	{
		buff[ret] = '\0';
		ptr->content = my_strjoinfree(ptr->content, buff, 1);
	}
	if (len > 0)
		((char*)ptr->content)[len - 1] = '\0';
	my_feed_line(&ptr, line, len);
	return ((len || **line) ? 1 : 0);
}
