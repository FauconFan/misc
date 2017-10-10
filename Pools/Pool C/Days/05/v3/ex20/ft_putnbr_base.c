/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 09:20:41 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 10:02:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		respect_norme_and_length_base(char *s)
{
	int		index[2];
	char	c;

	index[0] = 0;
	index[1] = 0;
	while (s[index[0]] != '\0')
	{
		c = s[index[0]];
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
			return (0);
		index[1] = index[0] + 1;
		while (s[index[1]] != '\0')
		{
			if (s[index[1]] == s[index[0]])
			{
				return (0);
			}
			index[1]++;
		}
		index[0]++;
	}
	return ((index[0] <= 1) ? 0 : index[0]);
}

void	print_number_recursive(int nbr, char *base, int length_base)
{
	if (nbr == 0)
		return ;
	print_number_recursive(nbr / length_base, base, length_base);
	ft_putchar(base[-(nbr % length_base)]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		length_base;

	length_base = respect_norme_and_length_base(base);
	if (length_base == 0)
		return ;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		print_number_recursive(nbr, base, length_base);
	}
	else
	{
		print_number_recursive(-nbr, base, length_base);
	}
}
