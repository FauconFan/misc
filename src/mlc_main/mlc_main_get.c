/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_main_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:38:03 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 15:10:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static int			verify_defines(void)
{
	if (TINY_MAX <= 0)
		return (1);
	if (TINY_MAX >= SMALL_MAX)
		return (1);
	if (TINY_MAX % 8 != 0)
		return (1);
	if (SMALL_MAX % 8 != 0)
		return (1);
	return (0);
}

static size_t		process_nb_pages_min(int pgsize, size_t min)
{
	return (1 +
		(sizeof(t_mlc_block) + min) * DEFAULT_MIN_ALLOC
			/ (pgsize - sizeof(t_mlc_ph)));
}

static void			process_nb_pages_init(
					int pgsize,
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

static t_mlc_main	*main_alloc(size_t *len, size_t page_size[2])
{
	t_mlc_main	*env;

	if ((env = mmap_good_size(len, 1)) == NULL)
		return (NULL);
	env->len_main = *len;
	env->tn_header = mlc_ph_new(page_size[0], 1);
	env->sm_header = mlc_ph_new(page_size[1], 1);
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
	return (env);
}

t_mlc_main			*mlc_main_get(void)
{
	size_t	len;
	size_t	page_size[2];

	if (g_mlc_main == NULL)
	{
		if (verify_defines() == 1)
			return (NULL);
		process_nb_pages_init(getpagesize(), page_size + 0, page_size + 1);
		len = sizeof(*g_mlc_main);
		g_mlc_main = main_alloc(&len, page_size);
	}
	return (g_mlc_main);
}

t_mlc_main			*g_mlc_main = NULL;
