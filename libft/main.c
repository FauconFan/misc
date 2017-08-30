#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	f(char *s)
{
	*s = *s + 1;
}

int 	main(void)
{
	// ft_putchar_fd('o', 1);
	// ft_putstr_fd("coucou\n", 1);
	// ft_putendl_fd("cou", 1);
	// ft_putnbr_fd(0, 1);

	// ft_putchar(ft_tolower('B'));
	// ft_putnbr(ft_strlen("coucou"));
	// ft_putnbr(ft_strncmp("ouia", "oui", 3));
	// ft_putchar('\n');
	// ft_putnbr(strncmp("ouia", "oui", 3));
	// ft_putchar('\n');

	char	s1[50] = "coucou";
	ft_striter(s1, f);
	ft_putendl(s1);
	// ft_strcpy(s1, "ok");
	// ft_putendl("---STRNSTR---");
	// ft_putendl((char *)strnstr(s1, s2));
	return 0;
}