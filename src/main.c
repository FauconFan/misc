#include "irc_udp.h"

void    test(void);

int main(void)
{
    int     juliusz;

    printf("Coucou le monde\n");

    juliusz = getSocketJuliusz();

    close(juliusz);

    return 0;
}
