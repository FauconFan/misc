#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include "s_answer.h"

static void		test(t_answer *ans, int (*function_test)(char const *), int (*function_real)(char const *), char *s)
{
	if (function_test((char const *)s) == function_real((char const *)s))
		ans_success(ans);
	else
	{
		libperso_putcol(MAGENTA, "str : ");
		libperso_putcol(MAGENTA, s);
		libperso_putcol(MAGENTA, " <=> function_test : ");
		libperso_putcol(MAGENTA, ft_itoa(function_test(s)));
		libperso_putcol(MAGENTA, " and function_real : ");
		libperso_putcol(MAGENTA, ft_itoa(function_real(s)));
		libperso_putcol(MAGENTA, "\n");
		ans_failed(ans);
	}
}

void			test_ft_atoi(void)
{
	t_answer	*ans;

	ans = init_answer("ft_atoi");
	test(ans, &ft_atoi, &atoi, "");
	test(ans, &ft_atoi, &atoi, "  245amis");
	test(ans, &ft_atoi, &atoi, " -é&è");
	test(ans, &ft_atoi, &atoi, " -2378chevaux");
	test(ans, &ft_atoi, &atoi, " +2390");
	test(ans, &ft_atoi, &atoi, "0");
	test(ans, &ft_atoi, &atoi, "    -0");
	print_n_free_result(ans);
}