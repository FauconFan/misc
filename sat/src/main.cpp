#include "sat.hpp"
#include <stdio.h>

extern int yyparse();
extern FILE *yyin;

static void test_bison_yacc(const char * path) {
    FILE *myfile = NULL;
    
    myfile = fopen(path, "r");
    if (!myfile) {
        std::cout << "I can't open my file!" << std::endl;
        return;
    }
    yyin = myfile;

    yyparse();

    FNC     *fnc;

    fnc = FNC_builder::get().getFNC();

    std::cout << *fnc << std::endl;

    delete fnc;

    fclose(myfile);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        test_bison_yacc(argv[1]);
    }
    else
        return (1);
    return (0);
}
