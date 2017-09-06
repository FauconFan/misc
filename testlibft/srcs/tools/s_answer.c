#include <stdlib.h>
#include "s_answer.h"
#include "functions.h"
#include "libft.h"
#include "libperso.h"

t_answer	*init_answer(char *function_name)
{
	t_answer	*res;

	if ((res = (t_answer *)malloc(sizeof(t_answer))) == NULL)
		return (NULL);
	res->function_name = function_name;
	res->nb_test = 1;
	res->is_test_passed = TEST_PASSED;
	return (res);
}

void		ans_success(t_answer *ans)
{
	ans->nb_test = ans->nb_test + 1;
}

void		ans_failed(t_answer *ans)
{
	ans->nb_test = ans->nb_test + 1;
	ans->is_test_passed = TEST_FAILED;
}

void		print_n_free_result(t_answer *ans)
{
	if (ans->is_test_passed == TEST_PASSED)
	{
		libperso_putcol(GREEN, ans->function_name);
		libperso_putcol(GREEN, " (nb_test : ");
		libperso_putcol(GREEN, ft_itoa(ans->nb_test - 1));
		libperso_putcol(GREEN, ") => OK\n");
	}
	else
	{
		libperso_putcol(RED, ans->function_name);
		libperso_putcol(RED, " (nb_test : ");
		libperso_putcol(RED, ft_itoa(ans->nb_test - 1));
		libperso_putcol(RED, ") => KO\n");
	}
	free(ans);
}