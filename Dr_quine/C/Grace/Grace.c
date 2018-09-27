#include <stdio.h>
#include <stdlib.h>

#define CODE        "#include <stdio.h>%c#include <stdlib.h>%c%c#define CODE        %c%s%c%c#define WRITE(ptr)  fprintf(ptr,CODE,10,10,10,34,CODE,34,10,10,10,34,34,34,34,10,10);%c%c#define FT()        int main(){FILE*fptr = fopen(%cGrace_kid.c%c,%cw%c); if(fptr==NULL) exit(1); WRITE(fptr) fclose(fptr); return (0);}%cFT()%c"
#define WRITE(ptr)  fprintf(ptr,CODE,10,10,10,34,CODE,34,10,10,10,34,34,34,34,10,10);

#define FT()        int main(){FILE*fptr = fopen("Grace_kid.c","w"); if(fptr==NULL) exit(1); WRITE(fptr) fclose(fptr); return (0);}
FT()
