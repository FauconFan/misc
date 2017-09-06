#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include <string.h>
#include "s_answer.h"

void	test(t_answer *ans, size_t (*function_test)(char const *), size_t (*function_real)(char const *), char *s)
{
	if (function_test((char const *)s) == function_real((char const *)s))
	{
		ans_success(ans);
	}
	else
	{
		ans_failed(ans);
	}
}

void	test_ft_strlen(void)
{
	t_answer	*ans;

	ans = init_answer("ft_strlen");
	test(ans, &ft_strlen, &strlen, "coucou");
	print_result(ans);
	free_answer(ans);
}