#include "libft.h"
#include <string.h>
#include <stdlib.h>

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

	// ft_putendl(ft_strtrim("  coucou je mappelle jojo      "));
	char	**res = ft_strsplit("  oui jaime beaucoup les pikachu  ", ' ');
	int		index = 0;
	while (res[index])
	{
		ft_putendl(res[index]);
		index++;
	}
	// ft_strcpy(s1, "ok");
	// ft_putendl("---STRNSTR---");
	// ft_putendl((char *)strnstr(s1, s2));
	return 0;
}