#include "test.h"
#include <stdlib.h>

int main(void) {
    start_test();

    void    *v;

    v = malloc(1);
    free(v);

    end_test();
    return (0);
}