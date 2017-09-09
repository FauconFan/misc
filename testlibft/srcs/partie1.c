#include "libft.h"
#include "libperso.h"
#include "functions.h"

void	test_mem(void)
{
	test_ft_memset();
	test_notimplementable("ft_bzero");
	test_notimplemented("ft_memcpy => ");
	test_notimplemented("ft_memccpy => ");
	test_notimplemented("ft_memmove => ");
	test_notimplemented("ft_memchr => ");
	test_notimplemented("ft_memcmp => ");
}

void	test_str(void)
{
	test_ft_strlen();
	test_notimplementable("ft_strdup");
	test_notimplemented("ft_strcpy => ");
	test_notimplemented("ft_strncpy => ");
	test_notimplemented("ft_strcat => ");
	test_notimplemented("ft_strncat => ");
	test_notimplemented("ft_strlcat => ");
	test_ft_strchr();
	test_ft_strrchr();
	test_notimplemented("ft_strstr => ");
	test_notimplemented("ft_strnstr => ");
	test_ft_strcmp();
	test_ft_strncmp();
}

void	test_is_to(void)
{
	test_ft_atoi();
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_toupper();
	test_ft_tolower();
}

void	test_partie1(void)
{
	h1(" PARTIE 1 ");
	test_mem();
	ft_putchar('\n');
	test_str();
	ft_putchar('\n');
	test_is_to();
	press_chr();
}