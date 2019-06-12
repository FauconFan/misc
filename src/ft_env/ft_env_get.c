/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:46:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 13:52:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static int			verify_defines(void)
{
	if (TINY_MAX <= 0)
		return (1);
	if (TINY_MAX >= SMALL_MAX)
		return (1);
	return (0);
}

static size_t		process_nb_pages_min(size_t pgsize, size_t min)
{
	size_t	denum;

	denum = pgsize - sizeof(t_ph);
	return (1 + (sizeof(t_blk) + min) * DEFAULT_MIN_ALLOC / denum);
}

static void			process_nb_pages_init(
					size_t pgsize,
					size_t *npage_tn,
					size_t *npage_sm)
{
	size_t	min_size;

	min_size = TINY_MAX - 1;
	size_multiple_16(&min_size);
	*npage_tn = process_nb_pages_min(pgsize, min_size) * pgsize;
	min_size = SMALL_MAX - 1;
	size_multiple_16(&min_size);
	*npage_sm = process_nb_pages_min(pgsize, min_size) * pgsize;
}

static t_env		*main_alloc(size_t *len, size_t page_size[2])
{
	t_env	*env;
	size_t	i;

	if ((env = mmap_good_size(len, 1)) == NULL)
		return (NULL);
	env->len_main = *len;
	env->tn_header = ft_ph_new(page_size[0], 1, NULL);
	env->sm_header = ft_ph_new(page_size[1], 1, NULL);
	env->lrg_header = NULL;
	if (env->tn_header == NULL || env->sm_header == NULL)
	{
		if (env->tn_header != NULL)
			munmap(env->sm_header, page_size[1]);
		if (env->sm_header != NULL)
			munmap(env->tn_header, page_size[0]);
		munmap(env, *len);
		return (NULL);
	}
	i = 0;
	while (i < BUFF_PAGE_CACHE)
	{
		env->tn_cache[i] = NULL;
		env->sm_cache[i++] = NULL;
	}
	return (env);
}

t_env				*ft_env_get(void)
{
	size_t	len;
	size_t	page_size[2];

	if (g_ft_env == NULL)
	{
		if (verify_defines() == 1)
			return (NULL);
		process_nb_pages_init((size_t)getpagesize(),
			page_size + 0,
			page_size + 1);
		len = sizeof(*g_ft_env);
		g_ft_env = main_alloc(&len, page_size);
	}
	return (g_ft_env);
}

t_env			*g_ft_env = NULL;
pthread_mutex_t	g_ft_env_mutex = PTHREAD_MUTEX_INITIALIZER;
