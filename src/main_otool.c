/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 07:21:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 11:56:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int			main(int argc, char **argv)
{
	t_ldf	ld;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (ft_ldf_init_mmap(&ld, argv[i], ft_strdup(argv[i]), TRUE) == FALSE)
			continue ;
		ft_otool(&ld);
		if (ft_ldf_end(&ld) == FALSE)
			continue ;
	}
	ft_buff_flush();
	return (0);
}
