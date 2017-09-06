#include "libft.h"
#include "libperso.h"
#include "functions.h"

void	do_test(void (*f1)(void), void (*f2)(void), void (*f3)(void))
{
	f1();
	ft_putchar('\n');
	f2();
	ft_putchar('\n');
	f3();
}