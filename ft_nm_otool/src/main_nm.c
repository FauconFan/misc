/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 07:21:08 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 10:30:29 by jpriou           ###   ########.fr       */
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
		if (ft_ldf_init(&ld, argv[i]) == FALSE)
			continue ;
		if (argc != 2)
		{
			ft_put_str_ln("");
			ft_put_str(ld.filepath);
			ft_put_str_ln(":");
		}
		ft_nm(&ld);
		if (ft_ldf_end(&ld) == FALSE)
			continue ;
	}
	return (0);
}
