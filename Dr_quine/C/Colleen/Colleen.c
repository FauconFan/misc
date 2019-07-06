#include <stdio.h>

/*
	Returns the code of the current program.
*/
char	*get_str(void)
{
	return ("#include <stdio.h>%3$c%3$c/*%3$c%2$cReturns the code of the current program.%3$c*/%3$cchar%2$c*get_str(void)%3$c{%3$c%2$creturn (%4$c%1$s%4$c);%3$c}%3$c%3$cint%2$c%2$cmain(void)%3$c{%3$c%2$c/*%3$c%2$c%2$cGet the code of the current program.%3$c%2$c*/%3$c%2$cchar *s = get_str();%3$c%3$c%2$cprintf(s, s, 9, 10, 34);%3$c%2$creturn (0);%3$c}%3$c");
}

int		main(void)
{
	/*
		Get the code of the current program.
	*/
	char *s = get_str();

	printf(s, s, 9, 10, 34);
	return (0);
}
