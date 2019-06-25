/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 07:21:08 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 11:56:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int			main(int argc, char **argv)
{
	t_ldf	ld;
	int		i;
	char	*name;

	i = 0;
	while (++i < argc)
	{
		name = ft_strformat1("\n%", argv[i]);
		if (ft_ldf_init_mmap(&ld, argv[i], name, argc != 2) == FALSE)
			continue ;
		ft_nm(&ld);
		if (ft_ldf_end(&ld) == FALSE)
			continue ;
	}
	ft_buff_flush();
	return (0);
}
