/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_print_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:29:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 11:55:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

inline void		ft_ldf_print_name(t_ldf *ldf)
{
	if (ldf->name == NULL || ldf->print_name == FALSE)
		return ;
	ft_bput_str(ldf->name);
	ft_bput_str_ln(":");
}
