#include <string.h>
#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include "s_answer.h"

static void		test(t_answer *ans, char *(*function_test)(char const *, int c), char *(*function_real)(char const *, int c), char *s, int c)
{
	if (ft_strcmp(function_test((char const *)s, c), function_real((char const *)s, c)) == 0)
		ans_success(ans);
	else
	{
		libperso_putcol(MAGENTA, "s & c : ");
		libperso_putcol(MAGENTA, s);
		libperso_putcol(MAGENTA, " ");
		libperso_putcol(MAGENTA, ft_itoa(c));
		libperso_putcol(MAGENTA, " <=> function_test : ");
		libperso_putcol(MAGENTA, function_test((char const *)s, c));
		libperso_putcol(MAGENTA, " and function_real : ");
		libperso_putcol(MAGENTA, function_real((char const *)s, c));
		libperso_putcol(MAGENTA, "\n");
		ans_failed(ans);
	}
}

void			test_ft_strchr(void)
{
	t_answer	*ans;

	ans = init_answer("ft_strchr");
	test(ans, &ft_strchr, &strchr, "cou", 'u');
	test(ans, &ft_strchr, &strchr, "cou", 'q');
	test(ans, &ft_strchr, &strchr, "coucou", 'c');
	test(ans, &ft_strchr, &strchr, "coucou", 'o');
	test(ans, &ft_strchr, &strchr, "coucou", 'u');
	print_n_free_result(ans);
}

void			test_ft_strrchr(void)
{
	t_answer	*ans;

	ans = init_answer("ft_strchr");
	test(ans, &ft_strrchr, &strrchr, "cou", 'u');
	test(ans, &ft_strrchr, &strrchr, "cou", 'q');
	test(ans, &ft_strrchr, &strrchr, "coucou", 'c');
	test(ans, &ft_strrchr, &strrchr, "coucou", 'o');
	test(ans, &ft_strrchr, &strrchr, "coucou", 'u');
	print_n_free_result(ans);
}