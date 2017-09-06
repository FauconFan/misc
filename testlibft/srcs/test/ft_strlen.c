#include <string.h>
#include "libft.h"
#include "libperso.h"
#include "functions.h"
#include "s_answer.h"

static void		test(t_answer *ans, size_t (*function_test)(char const *), size_t (*function_real)(char const *), char *s)
{
	if (function_test((char const *)s) == function_real((char const *)s))
		ans_success(ans);
	else
		ans_failed(ans);
}

void			test_ft_strlen(void)
{
	t_answer	*ans;

	ans = init_answer("ft_strlen");
	test(ans, &ft_strlen, &strlen, "ldfjldskjflsfjslkfjsldkfjsldkfjsldkfjsldkfj");
	test(ans, &ft_strlen, &strlen, "amzkeamkzencsnd azd a  az \n\n\ndd");
	test(ans, &ft_strlen, &strlen, "coucoudjflskfdjdsf");
	test(ans, &ft_strlen, &strlen, "coucouazkdjalzkjda\tttt");
	test(ans, &ft_strlen, &strlen, "coudslqkjdlqkjsdcou");
	test(ans, &ft_strlen, &strlen, "co54664654ucou");
	test(ans, &ft_strlen, &strlen, "couc254354354354354354354354ou");
	test(ans, &ft_strlen, &strlen, "coucamzkdmakzldmalkzdou");
	test(ans, &ft_strlen, &strlen, "coucou");
	test(ans, &ft_strlen, &strlen, "je");
	test(ans, &ft_strlen, &strlen, "");
	print_n_free_result(ans);
}