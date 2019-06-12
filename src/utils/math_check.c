#include "ft_malloc.h"

t_bool			do_mult_overflow(size_t a, size_t b)
{
	size_t	c;

	c = a * b;
	return (c / a != b);
}
