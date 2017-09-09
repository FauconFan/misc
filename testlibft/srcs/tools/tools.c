#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include "s_answer.h"

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

void	test_notimplementable(char *function_name)
{
	libperso_putcol(CYAN, function_name);
	libperso_putcol(YELLOW, "\tCouldn't be tested... Look at the code.\n");
}

void	do_testchr1(t_answer *ans, int (*function_test)(int), int (*function_real)(int),
	void (*test)(t_answer *, int (*)(int), int (*)(int), int c))
{
	int 	index;

	index = 0;
	while (index < 255)
	{
		test(ans, function_test, function_real, index);
		index++;
	}
}