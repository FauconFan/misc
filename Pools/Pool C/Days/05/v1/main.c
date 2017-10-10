/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:12:21 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 08:51:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putstr(char *str);
void	ft_putnbr(int n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strstr(char *str, char *to_find);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int nb);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putstr_non_printable(char *str);
//void	*ft_print_memory(void *addr, unsigned int size);

int		ft_putchar(char c);

int		main(void)
{
	ft_putstr("martine\n");
	ft_putnbr(42);
	ft_putchar('\n');
	char str1[] = "coucou";
	char str2[] = "saluuit!";
	ft_strncpy(str2, str1, 9);
	ft_putstr(str2);
	ft_putchar('\n');
	ft_putstr(strstr("coucou jaime les frafrites et la mayofri", "fri"));
	ft_putchar('\n');
	ft_putstr(ft_strstr("coucou jaime les frafrites et la mayofri", "fri"));
	ft_putchar('\n');
	char s1[] = "123";
	char s2[] = "42";
	char s3[] = "djoKIE12ds862'";
	ft_putnbr(strcmp(s1, s2));
	ft_putchar('\n');
	ft_putnbr(ft_strcmp(s1, s2));
	ft_putchar('\n');
	ft_putnbr(strncmp(s1, s2, 3));
	ft_putchar('\n');
	ft_putnbr(ft_strncmp(s1, s2, 3));
	ft_putchar('\n');
	ft_putstr(ft_strlowcase(s3));
	ft_putchar('\n');
	char s4[] = "coUcou J aime les 42gens Cool";
	ft_putstr(ft_strcapitalize(s4));
	ft_putchar('\n');
	ft_putnbr(ft_str_is_alpha(""));
	ft_putchar('\n');
	ft_putnbr(ft_str_is_numeric("456dhh44"));
	ft_putchar('\n');
	ft_putnbr(ft_str_is_lowercase("askhdjas4d"));
	ft_putchar('\n');
	ft_putnbr(ft_str_is_uppercase("DFDJdDJFJD"));
	ft_putchar('\n');
	char s5[] = "sdshfdkaj";
	ft_putstr(s5);
	ft_putchar('\n');
	ft_putnbr(ft_str_is_printable(s5));
	ft_putchar('\n');
	char s6[50] = "coucou";
	ft_putstr(ft_strcat(s6, s2));
	char s7[50] = "jaime";
	ft_putchar('\n');
	ft_putstr(ft_strncat(s6, s2, 1));
	ft_putchar('\n');
	ft_putnbr(strlcat(s7, s6, 1));
	ft_putchar('\n');
	ft_putstr(s7);
	ft_putchar('\n');
	ft_putnbr(strlen(s7));
	ft_putchar('\n');
	ft_putnbr_base(42, "13");
	ft_putchar('\n');
	ft_putstr_non_printable("coucou\r");
	ft_putchar('\n');
	int		a = 0x00000044;
	void	*addr = &a;
	//ft_print_memory(addr, 5);
	ft_putchar('\n');
}

int		ft_putchar(char c)
{
	int		ret;

	ret = write(1, &c, 1);
	return (ret);
}
