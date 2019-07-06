#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define		CONTENT	"#include <stdio.h>%3$c#include <stdlib.h>%3$c#include <unistd.h>%3$c#include <string.h>%3$c%3$c#define%2$c%2$cCONTENT%2$c%4$c%1$s%4$c%3$c%3$cint%2$cmain(void)%3$c{%3$c%2$cint%2$c%2$ci = %5$d;%3$c%2$cchar%2$cname_file[256];%3$c%2$cchar%2$cexe_file[256];%3$c%2$cchar%2$ccmd[1024];%3$c%2$cFILE%2$c*fptr;%3$c%3$c%2$cif (i < 0) return (0);%3$c%2$celse if (strchr(__FILE__, '_')) i--;%3$c%3$c%2$csprintf(name_file, %4$cSully_%%d.c%4$c, i);%3$c%2$csprintf(exe_file, %4$c./Sully_%%d%4$c, i);%3$c%3$c%2$cfptr = fopen(name_file, %4$cw%4$c);%3$c%2$cif (fptr == NULL)%3$c%2$c%2$creturn (1);%3$c%2$cfprintf(fptr, CONTENT, CONTENT, 9, 10, 34, i);%3$c%2$cfclose(fptr);%3$c%3$c%2$csprintf(cmd, %4$cgcc %%s -o %%s%4$c, name_file, exe_file);%3$c%2$csystem(cmd);%3$c%2$cif (i > 0)%3$c%2$c%2$csystem(exe_file);%3$c%2$creturn (0);%3$c}%3$c"

int	main(void)
{
	int		i = 5;
	char	name_file[256];
	char	exe_file[256];
	char	cmd[1024];
	FILE	*fptr;

	if (i < 0) return (0);
	else if (strchr(__FILE__, '_')) i--;

	sprintf(name_file, "Sully_%d.c", i);
	sprintf(exe_file, "./Sully_%d", i);

	fptr = fopen(name_file, "w");
	if (fptr == NULL)
		return (1);
	fprintf(fptr, CONTENT, CONTENT, 9, 10, 34, i);
	fclose(fptr);

	sprintf(cmd, "gcc %s -o %s", name_file, exe_file);
	system(cmd);
	if (i > 0)
		system(exe_file);
	return (0);
}
