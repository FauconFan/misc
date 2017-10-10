/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 08:20:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/18 09:59:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_list.h"
#include "ex00/ft_create_elem.c"
#include "ex01/ft_list_push_back.c"
#include "ex02/ft_list_push_front.c"
#include "ex03/ft_list_size.c"
#include "ex04/ft_list_last.c"
#include "ex05/ft_list_push_params.c"
#include "ex06/ft_list_clear.c"
#include "ex07/ft_list_at.c"
#include "ex08/ft_list_reverse.c"
#include "ex09/ft_list_foreach.c"
#include "ex10/ft_list_foreach_if.c"
#include "ex11/ft_list_find.c"
#include "ex12/ft_list_remove_if.c"
#include "ex13/ft_list_merge.c"
#include "ex14/ft_list_sort.c"
#include "ex15/ft_list_reverse_fun.c"
#include "ex16/ft_sorted_list_insert.c"
/*#include "ex17/ft_sorted_list_merge.c"*/

void	ft_putstr(char *str);
int		analyze_char(char *str);
void	print_title_exercise(int nb);
void	do_exercise(int nb);

void	crash_test_ex0(void);
void	crash_test_ex1(void);
void	crash_test_ex2(void);
void	crash_test_ex3(void);
void	crash_test_ex4(void);
void	crash_test_ex5(void);
void	crash_test_ex6(void);
void	crash_test_ex7(void);
void	crash_test_ex8(void);
void	crash_test_ex9(void);
void	crash_test_ex10(void);
void	crash_test_ex11(void);
void	crash_test_ex12(void);
void	crash_test_ex13(void);
void	crash_test_ex14(void);
void	crash_test_ex15(void);
void	crash_test_ex16(void);
void	crash_test_ex17(void);

t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_last);
t_list	*ft_list_push_params(int ac, char **av);
void	ft_list_clear(t_list **begin_last);
t_list	*ft_list_at(t_list *begin_last, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)(void *d1, void *d2));
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *d1, void *d2));
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *d1, void *d2));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list, int (*cmp(void *d1, void *d2)));
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)(void *d1, void *d2));
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)(void *d1, void *d2));

int		main(int argc, char **argv)
{
	int		ex_tested;

	printf("\033[031mAHAHA JE suis Bob lennon \033[0m");
	if (argc == 1)
	{
		ft_putstr("Please enter a valid number on argument\n");
	}
	else if (argc > 2)
	{
		ft_putstr("Not more than one argument.... x)\n");
	}
	else
	{
		ex_tested = analyze_char(argv[1]);
		if (ex_tested == -1)
		{
			ft_putstr("Please enter a valid number of exercise\n");
		}
		else
		{
			do_exercise(ex_tested);
		}
	}
	return (0);
}

void	do_exercise(int nb)
{
	void	(*tab[18])(void);

	print_title_exercise(nb);
	tab[0] = &crash_test_ex0;
	tab[1] = &crash_test_ex1;
	tab[2] = &crash_test_ex2;
	tab[3] = &crash_test_ex3;
	tab[4] = &crash_test_ex4;
	tab[5] = &crash_test_ex5;
	tab[6] = &crash_test_ex6;
	tab[7] = &crash_test_ex7;
	tab[8] = &crash_test_ex8;
	tab[9] = &crash_test_ex9;
	tab[10] = &crash_test_ex10;
	tab[11] = &crash_test_ex11;
	tab[12] = &crash_test_ex12;
	tab[13] = &crash_test_ex13;
	tab[14] = &crash_test_ex14;
	tab[15] = &crash_test_ex15;
	tab[16] = &crash_test_ex16;
	tab[17] = &crash_test_ex17;
	tab[nb]();
	ft_putstr("Exercice done !\n");
}

int		analyze_char(char *str)
{
	int		res;

	res = *str;
	res -= '0';
	if (res < 0 || res > 9)
		return (-1);
	str++;
	if (*str == 0)
		return (res);
	res = res * 10 + *str - '0';
	if (res < 10 || res > 17)
		return (-1);
	return (res);
}

void	ft_putstr(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	write(1, str, length);
}

void	print_title_exercise(int nb)
{
	char	s[3];

	ft_putstr("YEAH --------------------- ");
	if (nb < 10)
	{
		s[0] = nb + '0';
		s[1] = 0;
	}
	else
	{
		s[0] = (nb / 10) + '0';
		s[1] = (nb % 10) + '0';
		s[2] = 0;
	}
	ft_putstr(s);
	ft_putstr(" ------------------------ YEAH\n");
}

void	crash_test_ex0(void)
{
	t_list	*list;

	list = ft_create_elem("coucou");
	list = ft_create_elem(0);
}

void	crash_test_ex1(void)
{
	t_list	*list;

	ft_list_push_back(&list, 0);
	ft_list_push_back(&list, "coucou");
	ft_list_push_back(&list, 0);
	ft_list_push_back(&list, "vava");
	ft_list_push_back(&list, 0);
}

void	crash_test_ex2(void)
{
	t_list	*list;

	ft_list_push_front(&list, 0);
	ft_list_push_front(&list, "coucou");
	ft_list_push_front(&list, 0);
	ft_list_push_front(&list, "VALHALLA");
	ft_list_push_front(&list, 0);
}

void	crash_test_ex3(void)
{
	t_list	*list;

}

void	crash_test_ex4(void)
{
	
}

void	crash_test_ex5(void)
{
	
}

void	crash_test_ex6(void)
{
	
}

void	crash_test_ex7(void)
{
	
}

void	crash_test_ex8(void)
{
	
}

void	crash_test_ex9(void)
{
	
}

void	crash_test_ex10(void)
{
	
}

void	crash_test_ex11(void)
{
	
}

void	crash_test_ex12(void)
{
	
}

void	crash_test_ex13(void)
{
	
}

void	crash_test_ex14(void)
{
	
}

void	crash_test_ex15(void)
{
	
}

void	crash_test_ex16(void)
{
	
}

void	crash_test_ex17(void)
{
	
}
