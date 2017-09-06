#include <string.h>
#include <ctype.h>
#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include "s_answer.h"

static void		test(t_answer *ans, int (*function_test)(int), int (*function_real)(int), int c)
{
	if (function_test(c) == function_real(c))
		ans_success(ans);
	else
		ans_failed(ans);
}

void			test_ft_toupper(void)
{
	t_answer	*ans;

	ans = init_answer("ft_toupper");
	do_testchr1(ans, &ft_toupper, &toupper, &test);
	print_n_free_result(ans);
}

void			test_ft_tolower(void)
{
	t_answer	*ans;

	ans = init_answer("ft_tolower");
	do_testchr1(ans, &ft_tolower, &tolower, &test);
	print_n_free_result(ans);
}

void			test_ft_isascii(void)
{
	t_answer	*ans;

	ans = init_answer("ft_isascii");
	do_testchr1(ans, &ft_isascii, &isascii, &test);
	print_n_free_result(ans);
}