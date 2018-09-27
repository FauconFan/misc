#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define  CONTENT  "#include <stdio.h>%c#include <stdlib.h>%c#include <unistd.h>%c#include <string.h>%c%c#define  CONTENT  %c%s%c%c%cint main()%c{%c  int     i = %d;%c  char    name_file[128];%c  char    exe_file[128];%c  char    cmd[1024];%c  FILE    *fptr;%c%c  if (i < 0) return (0);%c  else if (strchr(__FILE__, '_')) i--;%c%c  sprintf(name_file, %cSully_%%d.c%c, i);%c  sprintf(exe_file, %c./Sully_%%d%c, i);%c%c  fptr = fopen(name_file, %cw%c);%c  if (fptr == NULL)%c    return (1);%c  fprintf(fptr, CONTENT, 10, 10, 10, 10, 10, 34, CONTENT, 34, 10, 10, 10, 10, i, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, 34, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10);%c  fclose(fptr);%c%c  sprintf(cmd, %cgcc %%s -o %%s%c, name_file, exe_file);%c  system(cmd);%c  if (i > 0)%c    system(exe_file);%c  return (0);%c}%c"

int main(int argc, char **argv)
{
  int     i = 5;
  char    name_file[128];
  char    exe_file[128];
  char    cmd[1024];
  FILE    *fptr;

  if (argc == 2)
    i = atoi(argv[1]);
  if (i < 0) return (0);
  else if (strchr(__FILE__, '_')) i--;

  sprintf(name_file, "Sully_%d.c", i);
  sprintf(exe_file, "./Sully_%d", i);

  fptr = fopen(name_file, "w");
  if (fptr == NULL)
    return (1);
  fprintf(fptr, CONTENT, 10, 10, 10, 10, 10, 34, CONTENT, 34, 10, 10, 10, 10, i, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, 34, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10);
  fclose(fptr);

  sprintf(cmd, "gcc %s -o %s", name_file, exe_file);
  system(cmd);
  if (i > 0)
    system(exe_file);
  return (0);
}
