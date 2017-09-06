#include "libft.h"
#include "libperso.h"
#include "functions.h"

void	test_mem(void)
{
	libperso_putcol(CYAN, "ft_memset => ");
	no();
	libperso_putcol(CYAN, "ft_bzero => ");
	no();
	libperso_putcol(CYAN, "ft_memcpy => ");
	no();
	libperso_putcol(CYAN, "ft_memccpy => ");
	no();
	libperso_putcol(CYAN, "ft_memmove => ");
	no();
	libperso_putcol(CYAN, "ft_memchr => ");
	no();
	libperso_putcol(CYAN, "ft_memcmp => ");
	no();
}

void	test_str(void)
{
	libperso_putcol(CYAN, "ft_strlen => ");
	no();
	libperso_putcol(CYAN, "ft_strdup => ");
	no();
	libperso_putcol(CYAN, "ft_strcpy => ");
	no();
	libperso_putcol(CYAN, "ft_strncpy => ");
	no();
	libperso_putcol(CYAN, "ft_strcat => ");
	no();
	libperso_putcol(CYAN, "ft_strncat => ");
	no();
	libperso_putcol(CYAN, "ft_strlcat => ");
	no();
	libperso_putcol(CYAN, "ft_strchr => ");
	no();
	libperso_putcol(CYAN, "ft_strrchr => ");
	no();
	libperso_putcol(CYAN, "ft_strstr => ");
	no();
	libperso_putcol(CYAN, "ft_strnstr => ");
	no();
	libperso_putcol(CYAN, "ft_strcmp => ");
	no();
	libperso_putcol(CYAN, "ft_strncmp => ");
	no();
}

void	test_is_to(void)
{
	libperso_putcol(CYAN, "ft_atoi => ");
	no();
	libperso_putcol(CYAN, "ft_isalpha => ");
	no();
	libperso_putcol(CYAN, "ft_isdigit => ");
	no();
	libperso_putcol(CYAN, "ft_isalnum => ");
	no();
	libperso_putcol(CYAN, "ft_isascii => ");
	no();
	libperso_putcol(CYAN, "ft_isprint => ");
	no();
	libperso_putcol(CYAN, "ft_toupper => ");
	no();
	libperso_putcol(CYAN, "ft_tolower => ");
	no();
}

void	test_partie1(void)
{
	h1(" PARTIE 1 ");
	do_test(&test_mem, &test_str, &test_is_to);
}