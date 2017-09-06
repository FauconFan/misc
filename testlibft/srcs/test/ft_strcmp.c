#include <string.h>
#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include "s_answer.h"

static void		test(t_answer *ans,
					int (*function_test)(char const *, char const *),
					int (*function_real)(char const *, char const *),
					char *s1,
					char *s2)
{
	if (function_test((char const *)s1, (char const *)s2) ==
		function_real((char const *)s1, (char const *)s2))
		ans_success(ans);
	else
	{
		libperso_putcol(MAGENTA, "s1 & s2 : ");
		libperso_putcol(MAGENTA, s1);
		libperso_putcol(MAGENTA, " ");
		libperso_putcol(MAGENTA, s2);
		libperso_putcol(MAGENTA, " <=> function_test : ");
		libperso_putcol(MAGENTA, ft_itoa(function_test((char const *)s1, (char const *)s2)));
		libperso_putcol(MAGENTA, " and function_real : ");
		libperso_putcol(MAGENTA, ft_itoa(function_real((char const *)s1, (char const *)s2)));
		libperso_putcol(MAGENTA, "\n");
		ans_failed(ans);
	}
}

static void		test2(t_answer *ans,
					int (*function_test)(char const *, char const *, size_t),
					int (*function_real)(char const *, char const *, size_t),
					char *s1,
					char *s2,
					size_t size)
{
	if (function_test((char const *)s1, (char const *)s2, size) ==
		function_real((char const *)s1, (char const *)s2, size))
		ans_success(ans);
	else
	{
		libperso_putcol(MAGENTA, "s1 & s2 & size : ");
		libperso_putcol(MAGENTA, s1);
		libperso_putcol(MAGENTA, " ");
		libperso_putcol(MAGENTA, s2);
		libperso_putcol(MAGENTA, " ");
		libperso_putcol(MAGENTA, ft_itoa((int) size));
		libperso_putcol(MAGENTA, " <=> function_test : ");
		libperso_putcol(MAGENTA, ft_itoa(function_test((char const *)s1, (char const *)s2, size)));
		libperso_putcol(MAGENTA, " and function_real : ");
		libperso_putcol(MAGENTA, ft_itoa(function_real((char const *)s1, (char const *)s2, size)));
		libperso_putcol(MAGENTA, "\n");
		ans_failed(ans);
	}
}

void			test_ft_strcmp(void)
{
	t_answer	*ans;

	ans = init_answer("ft_strcmp");
	test(ans, &ft_strcmp, &strcmp, "", "");
	test(ans, &ft_strcmp, &strcmp, "a", "");
	test(ans, &ft_strcmp, &strcmp, "", "a");
	test(ans, &ft_strcmp, &strcmp, "ab", "ab");
	test(ans, &ft_strcmp, &strcmp, "a", "b");
	test(ans, &ft_strcmp, &strcmp, "ab", "ba");
	test(ans, &ft_strcmp, &strcmp, "coucou", "coucou");
	test(ans, &ft_strcmp, &strcmp, "ouioui", "ouiou");
	print_n_free_result(ans);
}

void			test_ft_strncmp(void)
{
	t_answer	*ans;

	ans = init_answer("ft_strncmp");
	test2(ans, &ft_strncmp, &strncmp, "", "", 0);
	test2(ans, &ft_strncmp, &strncmp, "", "", 1);
	test2(ans, &ft_strncmp, &strncmp, "", "", 2);
	test2(ans, &ft_strncmp, &strncmp, "a", "", 0);
	test2(ans, &ft_strncmp, &strncmp, "", "a", 0);
	test2(ans, &ft_strncmp, &strncmp, "a", "", 1);
	test2(ans, &ft_strncmp, &strncmp, "", "a", 1);
	test2(ans, &ft_strncmp, &strncmp, "a", "", 2);
	test2(ans, &ft_strncmp, &strncmp, "", "a", 2);
	test2(ans, &ft_strncmp, &strncmp, "ab", "ab", 1);
	test2(ans, &ft_strncmp, &strncmp, "ab", "ab", 2);
	test2(ans, &ft_strncmp, &strncmp, "ab", "ab", 3);
	test2(ans, &ft_strncmp, &strncmp, "a", "b", 0);
	test2(ans, &ft_strncmp, &strncmp, "a", "b", 1);
	test2(ans, &ft_strncmp, &strncmp, "ab", "ba", 0);
	test2(ans, &ft_strncmp, &strncmp, "ab", "ba", 1);
	test2(ans, &ft_strncmp, &strncmp, "ab", "ba", 2);
	test2(ans, &ft_strncmp, &strncmp, "ab", "ba", 3);
	test2(ans, &ft_strncmp, &strncmp, "ouioui", "ouiou", 4);
	test2(ans, &ft_strncmp, &strncmp, "ouioui", "ouiou", 5);
	test2(ans, &ft_strncmp, &strncmp, "ouioui", "ouiou", 6);
	test2(ans, &ft_strncmp, &strncmp, "ouioui", "ouiou", 7);
	print_n_free_result(ans);
}