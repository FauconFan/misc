#include "libft.h"
#include "libperso.h"
#include "functions.h"

void	do_test(void (*f1)(void), void (*f2)(void), void (*f3)(void))
{
	f1();
	ft_putchar('\n');
	f2();
	ft_putchar('\n');
	f3();
}

void	test_passed(char *function_name)
{
	libperso_putcol(GREEN, "TEST PASSED : ");
	libperso_putcol(GREEN, function_name);
	libperso_putcol(GREEN, " => OK\n");
}

void	test_failed(char *function_name)
{
	libperso_putcol(RED, "TEST FAILED : ");
	libperso_putcol(RED, function_name);
	libperso_putcol(RED, " => KO\n");
}

void	test_notimplemented(char *function_name)
{
	libperso_putcol(CYAN, function_name);
	libperso_putcol(MAGENTA, "\tTest not implemented yet\n");
}