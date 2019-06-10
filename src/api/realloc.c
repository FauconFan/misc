/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:48:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 15:10:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	copy_buffer(void *ptr, char *next, size_t len_out, size_t len_in)
{
	size_t i;

	if (len_out > len_in)
		len_out = len_in;
	i = 0;
	while (i < len_out)
	{
		next[i] = ((char *)ptr)[i];
		++i;
	}
}

void		*realloc(void *ptr, size_t len_out)
{
	t_mlc_block	*blk;
	t_mlc_main	*env;
	char		*next;
	size_t		len_in;

	if (ptr == NULL)
		return (malloc(len_out));
	env = mlc_main_get();
	next = NULL;
	if (env != NULL)
	{
		len_in = mlc_main_find_free(env, ptr);
		if (len_in == 0)
			return (NULL);
		blk = mlc_main_find_alloc(env, len_out);
		if (blk != NULL)
		{
			next = (char *)(blk + 1);
			copy_buffer(ptr, next, len_out, len_in);
		}
	}
	return (next);
}
