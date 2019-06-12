/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:48:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 13:31:15 by jpriou           ###   ########.fr       */
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
	t_blk		*blk;
	t_env		*env;
	char		*next;
	size_t		len_in;

	if (ptr == NULL)
		return (malloc(len_out));
	if (len_out == 0)
		len_out = 16;
	env = ft_env_get();
	next = NULL;
	if (env != NULL)
	{
		len_in = ft_env_find_free(env, ptr);
		if (len_in == 0)
			return (NULL);
		blk = ft_env_alloc(env, len_out);
		if (blk != NULL)
		{
			next = (char *)(blk + 1);
			copy_buffer(ptr, next, len_out, len_in);
		}
		ft_env_clear(env);
	}
	return (next);
}
