#include <stdio.h>
#include <stdlib.h>

#define CODE		"#include <stdio.h>%3$c#include <stdlib.h>%3$c%3$c#define CODE%2$c%2$c%4$c%1$s%4$c%3$c#define WRITE(ptr)%2$cfprintf(ptr, CODE, CODE, 9, 10, 34)%3$c%3$c#define FT()%2$c%2$cint main(){ FILE *fptr = fopen(%4$cGrace_kid.c%4$c, %4$cw%4$c); if(fptr == NULL) exit(1); WRITE(fptr); fclose(fptr); return (0); }%3$c%3$cFT()%3$c"
#define WRITE(ptr)	fprintf(ptr, CODE, CODE, 9, 10, 34)

#define FT()		int main(){ FILE *fptr = fopen("Grace_kid.c", "w"); if(fptr == NULL) exit(1); WRITE(fptr); fclose(fptr); return (0); }

FT()
