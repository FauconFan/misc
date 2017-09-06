#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include "s_answer.h"

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

void	do_testchr1(t_answer *ans, int (*function_test)(int), int (*function_real)(int),
	void (*test)(t_answer *, int (*)(int), int (*)(int), int c))
{
	int 	index;

	index = 0;
	while (index < 128)
	{
		test(ans, function_test, function_real, index);
		index++;
	}
	test(ans, function_test, function_real, 500);
	test(ans, function_test, function_real, 10000);
}