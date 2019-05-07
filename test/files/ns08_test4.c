#include "test.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print(char *s)
{
    write(1, s, strlen(s));
}

int main()
{
    start_test();
    char *addr;

    addr = malloc(16);
    free(NULL);
    free((void *)addr + 5);
    if (realloc((void *)addr + 5, 10) == NULL)
    print("Bonjours\n");
    end_test();
}