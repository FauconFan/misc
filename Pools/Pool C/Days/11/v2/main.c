/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 08:55:01 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/17 08:25:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

void	my_putstr(char *str);
void	my_putnbr(int nb);
void	my_putnbrpos(int nb);
int		change(void *str, void *str2);
void	print_list(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_remove_if(t_list **begin_list, void *data_ef, int (*cmp)(void *s1, void *s2));

int		main(int argc, char **argv)
{
	t_list	*list;

	list = 0;
	ft_list_push_back(&list, (void *)"ALEDAUSEKOUR");
	ft_list_push_back(&list, (void *)"ALEDAUSEKOUR");
	ft_list_push_back(&list, (void *)"allezzzz");
	ft_list_push_back(&list, (void *)"ALEDAUSEKOUR");
	ft_list_push_back(&list, (void *)"ALEDAUSEKOUR");
	ft_list_push_back(&list, (void *)"ALEDAUSEKOUR");
	print_list(list);
	my_putstr("-----------------OUI----------------------\n");
	ft_list_remove_if(&list, (void *)"coucou", &change);
	print_list(list);
}

void	my_putstr(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	write(1, str, length);
}

void	my_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		my_putnbrpos(nb);
	}
}

void	my_putnbrpos(int nb)
{
	char c;

	if (nb == 0)
		return ;
	my_putnbrpos(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	print_list(t_list *begin_list)
{
	if (begin_list == 0)
		return ;
	my_putstr((char *)begin_list->data);
	write(1, "\n", 1);
	print_list(begin_list->next);
}

int		change(void *str, void *str2)
{
	char	*s;

	s = (char *)str;
	if (s[0] == 'A')
		return (0);
	return (1);
}
