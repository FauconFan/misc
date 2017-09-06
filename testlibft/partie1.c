#include "libft.h"
#include "libperso.h"
#include "functions.h"

void	test_mem(void)
{
	test_notimplemented("ft_memset => ");
	test_notimplemented("ft_bzero => ");
	test_notimplemented("ft_memcpy => ");
	test_notimplemented("ft_memccpy => ");
	test_notimplemented("ft_memmove => ");
	test_notimplemented("ft_memchr => ");
	test_notimplemented("ft_memcmp => ");
}

void	test_str(void)
{
	test_notimplemented("ft_strlen => ");
	test_notimplemented("ft_strdup => ");
	test_notimplemented("ft_strcpy => ");
	test_notimplemented("ft_strncpy => ");
	test_notimplemented("ft_strcat => ");
	test_notimplemented("ft_strncat => ");
	test_notimplemented("ft_strlcat => ");
	test_notimplemented("ft_strchr => ");
	test_notimplemented("ft_strrchr => ");
	test_notimplemented("ft_strstr => ");
	test_notimplemented("ft_strnstr => ");
	test_notimplemented("ft_strcmp => ");
	test_notimplemented("ft_strncmp => ");
}

void	test_is_to(void)
{
	test_notimplemented("ft_atoi => ");
	test_notimplemented("ft_isalpha => ");
	test_notimplemented("ft_isdigit => ");
	test_notimplemented("ft_isalnum => ");
	test_notimplemented("ft_isascii => ");
	test_notimplemented("ft_isprint => ");
	test_notimplemented("ft_toupper => ");
	test_notimplemented("ft_tolower => ");
}

void	test_partie1(void)
{
	h1(" PARTIE 1 ");
	do_test(&test_mem, &test_str, &test_is_to);
}