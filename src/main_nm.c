/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 07:21:08 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 09:38:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	do_main(char *argv, t_bool print_name)
{
	t_ldf	ld;
	char	*name;

	name = ft_strformat1("\n%", argv);
	if (ft_ldf_init_mmap(&ld, argv, name, print_name) == FALSE)
		return ;
	ft_nm(&ld);
	if (ft_ldf_end(&ld) == FALSE)
		return ;
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		do_main("a.out", FALSE);
	i = 0;
	while (++i < argc)
		do_main(argv[i], argc != 2);
	ft_buff_flush();
	return (0);
}
