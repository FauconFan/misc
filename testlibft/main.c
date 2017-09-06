#include "libft.h"
#include "libperso.h"
#include "functions.h"

void	no(void)
{
	libperso_putcol(MAGENTA, "\tTest not implemented yet\n");
}

int		main(void)
{
	clrsrc();
	test_partie1();
	test_partie2();
	return (0);
}