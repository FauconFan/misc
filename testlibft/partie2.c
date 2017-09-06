#include "libft.h"
#include "libperso.h"
#include "functions.h"

void	test_mem2(void)
{
	libperso_putcol(CYAN, "ft_memalloc => ");
	no();
	libperso_putcol(CYAN, "ft_memdel => ");
	no();
}

void	test_str2(void)
{
	libperso_putcol(CYAN, "ft_strnew => ");
	no();
	libperso_putcol(CYAN, "ft_strdel => ");
	no();
	libperso_putcol(CYAN, "ft_strclr => ");
	no();
	libperso_putcol(CYAN, "ft_striter => ");
	no();
	libperso_putcol(CYAN, "ft_striteri => ");
	no();
	libperso_putcol(CYAN, "ft_strmap => ");
	no();
	libperso_putcol(CYAN, "ft_strmapi => ");
	no();
	libperso_putcol(CYAN, "ft_strequ => ");
	no();
	libperso_putcol(CYAN, "ft_strnequ => ");
	no();
	libperso_putcol(CYAN, "ft_strsub => ");
	no();
	libperso_putcol(CYAN, "ft_strjoin => ");
	no();
	libperso_putcol(CYAN, "ft_strtrim => ");
	no();
	libperso_putcol(CYAN, "ft_strsplit => ");
	no();
	libperso_putcol(CYAN, "ft_stritoa => ");
	no();
}

void	test_put(void)
{
	libperso_putcol(CYAN, "ft_putchar => ");
	no();
	libperso_putcol(CYAN, "ft_putstr => ");
	no();
	libperso_putcol(CYAN, "ft_putendl => ");
	no();
	libperso_putcol(CYAN, "ft_putnbr => ");
	no();
	libperso_putcol(CYAN, "ft_putchar_fd => ");
	no();
	libperso_putcol(CYAN, "ft_putstr_fd => ");
	no();
	libperso_putcol(CYAN, "ft_putendl_fd => ");
	no();
	libperso_putcol(CYAN, "ft_putnbr_fd => ");
	no();
}

void	test_partie2(void)
{
	h1(" PARTIE 2 ");
	do_test(&test_mem2, &test_str2, &test_put);
}