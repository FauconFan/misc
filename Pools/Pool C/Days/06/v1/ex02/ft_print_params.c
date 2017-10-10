/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:49:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 13:52:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		index;
	int		letter;

	index = 1;
	while (index < argc)
	{
		letter = 0;
		while (argv[index][letter])
		{
			ft_putchar(argv[index][letter++]);
		}
		ft_putchar('\n');
		index++;
	}
}
