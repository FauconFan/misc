/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_ph_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:40:26 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:40:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_mlc_ph	*mlc_ph_new(size_t size, size_t mult)
{
	t_mlc_ph	*res;

	res = (t_mlc_ph *)mmap_good_size(&size, mult);
	if (res == NULL)
		return (NULL);
	res->len_page = size;
	res->next_page = NULL;
	mlc_block_init(res + 1, res->len_page - sizeof(t_mlc_ph));
	return (res);
}
