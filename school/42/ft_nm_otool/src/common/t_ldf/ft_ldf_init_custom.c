/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_init_custom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:48:12 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 11:52:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_ldf_init_custom(t_ldf *ld, char *name, void *v, size_t len)
{
	ft_bzero(ld, sizeof(*ld));
	ld->is_mmap = FALSE;
	ld->print_name = TRUE;
	ld->name = name;
	ld->content = v;
	ld->len = len;
}
