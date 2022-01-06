/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:41:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:41:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*mmap_brut(size_t size)
{
	void	*v;

	v = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (v == MAP_FAILED)
		return (NULL);
	return (v);
}

void		*mmap_good_size(size_t *size, size_t mult)
{
	int		pgsize;
	void	*v;

	pgsize = getpagesize();
	if (pgsize <= 0 || size == NULL || *size == 0)
		return (NULL);
	size_multiple_page(size);
	if (mult > 1)
		*size *= mult;
	v = mmap_brut(*size);
	if (v == NULL)
		*size = 0;
	return (v);
}
