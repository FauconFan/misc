/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 09:31:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/05 10:09:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_one_line(int x, char	*template);
char	*get_header();
char	*get_body();
char	*get_footer();

void	rush(int x, int y)
{
	int		index;

	if (y <= 0)
		return ;
	print_one_line(x, get_header());
	y--;
	if (y <= 0)
		return ;
	index = 0;
	while (index <= y - 1)
	{
		print_one_line(x, get_body());
		index++;
	}
	if (y != -1)
	{
		print_one_line(x, get_footer());
	}
}

char	*get_header(void)
{
	return ("/*\\");
}

char	*get_body(void)
{
	return ("* *");
}

char	*get_footer(void)
{
	return ("\\*/");
}

void	print_one_line(int x, char *template)
{
	int		index;

	index = 0;
	if (x <= 0)
		return ;
	if (x <= 2)
	{
		ft_putchar(template[0]);
		if (x == 2)
			ft_putchar(template[2]);
		ft_putchar('\n');
		return ;
	}
	ft_putchar(template[0]);
	while (index <= x - 2)
	{
		ft_putchar(template[1]);
		index++;
	}
	ft_putchar(template[2]);
	ft_putchar('\n');
}
