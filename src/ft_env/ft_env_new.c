/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 09:02:40 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 10:09:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static size_t		process_nb_pages_min(size_t pgsize, size_t min)
{
	size_t	denum;

	denum = pgsize - sizeof(t_ph);
	return (1 + (sizeof(t_blk) + min) * DEFAULT_MIN_ALLOC / denum);
}

static void			process_nb_pages_init(
					size_t pgsize,
					size_t *npage)
{
	size_t	min_size;

	min_size = TINY_MAX - 1;
	size_multiple_16(&min_size);
	npage[0] = process_nb_pages_min(pgsize, min_size) * pgsize;
	min_size = SMALL_MAX - 1;
	size_multiple_16(&min_size);
	npage[1] = process_nb_pages_min(pgsize, min_size) * pgsize;
}

static t_env		*handle_error(t_env *env, t_bool fail)
{
	if (fail || env->tn_header == NULL || env->sm_header == NULL)
	{
		if (env->tn_header != NULL)
			ft_ph_munmap(env->tn_header, TRUE);
		if (env->sm_header != NULL)
			ft_ph_munmap(env->sm_header, TRUE);
		munmap(env, env->len_main);
		return (NULL);
	}
	return (env);
}

static void			init_mutex(t_env *env)
{
	static const pthread_mutex_t	init = PTHREAD_MUTEX_INITIALIZER;

	ft_memcpy((env + 1), &init, sizeof(init));
}

t_env				*ft_env_new(t_bool is_malloc_zone)
{
	t_env	*env;
	size_t	page_size[2];
	size_t	len;

	len = sizeof(t_env);
	if ((env = mmap_good_size(&len, 1)) == NULL)
		return (NULL);
	process_nb_pages_init((size_t)getpagesize(), page_size);
	env->len_main = len;
	env->tn_header = ft_ph_new(page_size[0], 1, NULL);
	env->sm_header = ft_ph_new(page_size[1], 1, NULL);
	env->lrg_header = NULL;
	ft_bzero(env->tn_cache, sizeof(t_ph) * BUFF_PAGE_CACHE);
	ft_bzero(env->sm_cache, sizeof(t_ph) * BUFF_PAGE_CACHE);
	env->is_malloc_zone = is_malloc_zone;
	if (is_malloc_zone)
	{
		if (len < sizeof(t_env) + sizeof(pthread_mutex_t))
			return (handle_error(env, TRUE));
		init_mutex(env);
	}
	return (handle_error(env, FALSE));
}
