#include <stdio.h>
#include "libperso.h"

void	press_chr(void)
{
	char	c;

	libperso_putcol(WHITE, "(press enter...)");
	scanf("%c", &c);
}