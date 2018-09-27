#include <stdio.h>

/*
   Returns the code of the current program.
*/
char *get_str()
{
  return "#include <stdio.h>%c%c/*%c   Returns the code of the current program.%c*/%cchar *get_str()%c{%c  return %c%s%c;%c}%c%cint main()%c{%c  /*%c     Get the code of the current program.%c  */%c  char *s = get_str();%c%c  printf(s,10,10,10,10,10,10,10,34,s,34,10,10,10,10,10,10,10,10,10,10,10,10,10);%c  return (0);%c}%c";
}

int main()
{
  /*
     Get the code of the current program.
  */
  char *s = get_str();

  printf(s,10,10,10,10,10,10,10,34,s,34,10,10,10,10,10,10,10,10,10,10,10,10,10);
  return (0);
}
