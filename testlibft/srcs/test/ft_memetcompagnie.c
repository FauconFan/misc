#include <string.h>
#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include "s_answer.h"

static void		init_str(char *s)
{
	int 	index;

	index = 0;
	while (index < 26)
	{
		s[index] = index + 'a';
		index++;
	}
	s[index] = 0;
}

static void		test(t_answer *ans, int c, int num)
{
	char		tmp[30];
	char		tmp2[30];

	init_str(tmp);
	init_str(tmp2);
	if (ft_strcmp(ft_memset((void *)tmp, c, num), memset((void *)tmp2, c, num)) == 0)
		ans_success(ans);
	else
	{
		libperso_putcol(MAGENTA, "s1 & s2 : (function_test) ");
		libperso_putcol(MAGENTA, tmp);
		libperso_putcol(MAGENTA, " (function_real) ");
		libperso_putcol(MAGENTA, tmp2);
		libperso_putcol(MAGENTA, "\n");
		ans_failed(ans);
	}
}

void			test_ft_memset(void)
{
	t_answer	*ans;

	ans = init_answer("ft_memset");
	test(ans, '/', 5);
	test(ans, '|', 6);
	test(ans, '/', 8);
	test(ans, 'i', 9);
	test(ans, 'p', 0);
	test(ans, 'a', 30);
	test(ans, '+', 1);
	print_n_free_result(ans);
}