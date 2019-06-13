/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:46:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 16:00:49 by jpriou           ###   ########.fr       */
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

static void			env_setup(void)
{
	char	*st;

	st = getenv(AT_EXIT_TAG);
	if (st != NULL)
	{
		if (ft_strequ(st, AT_EXIT_TAG_HEX))
			atexit(show_alloc_mem_hex);
		else
			atexit(show_alloc_mem);
	}
}

t_env				*ft_env_get(void)
{
	if (g_ft_env == NULL)
	{
		if (verify_defines() == 1)
			return (NULL);
		env_setup();
		g_ft_env = ft_env_new(FALSE);
	}
	return (g_ft_env);
}

t_env			*g_ft_env = NULL;
pthread_mutex_t	g_ft_env_mutex = PTHREAD_MUTEX_INITIALIZER;
