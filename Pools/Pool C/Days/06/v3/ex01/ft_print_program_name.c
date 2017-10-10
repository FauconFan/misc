/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:42:23 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 08:17:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		index;

	if (argc > 0)
	{
		index = 0;
		while (argv[0][index])
		{
			ft_putchar(argv[0][index]);
			index++;
		}
		ft_putchar('\n');
	}
	return (0);
}
