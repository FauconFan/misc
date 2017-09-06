#include "libft.h"
#include "libperso.h"
#include "functions.h"

void	test_mem2(void)
{
	test_notimplemented("ft_memalloc => ");
	test_notimplemented("ft_memdel => ");
}

void	test_str2(void)
{
	test_notimplemented("ft_strnew => ");
	test_notimplemented("ft_strdel => ");
	test_notimplemented("ft_strclr => ");
	test_notimplemented("ft_striter => ");
	test_notimplemented("ft_striteri => ");
	test_notimplemented("ft_strmap => ");
	test_notimplemented("ft_strmapi => ");
	test_notimplemented("ft_strequ => ");
	test_notimplemented("ft_strnequ => ");
	test_notimplemented("ft_strsub => ");
	test_notimplemented("ft_strjoin => ");
	test_notimplemented("ft_strtrim => ");
	test_notimplemented("ft_strsplit => ");
	test_notimplemented("ft_stritoa => ");
}

void	test_put(void)
{
	test_notimplemented("ft_putchar => ");
	test_notimplemented("ft_putstr => ");
	test_notimplemented("ft_putendl => ");
	test_notimplemented("ft_putnbr => ");
	test_notimplemented("ft_putchar_fd => ");
	test_notimplemented("ft_putstr_fd => ");
	test_notimplemented("ft_putendl_fd => ");
	test_notimplemented("ft_putnbr_fd => ");
}

void	test_partie2(void)
{
	h1(" PARTIE 2 ");
	do_test(&test_mem2, &test_str2, &test_put);
}