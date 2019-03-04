#include "sat.hpp"

extern int yyparse();
extern FILE *yyin;

FNC     *getInputFNC(const char * path) {
    FILE    *file = NULL;
    FNC     *fnc = NULL;

    file = fopen(path, "r");
    if (file == NULL) {
        std::cerr << "I can't open the file : " << path << std::endl;
        return (NULL);
    }
    yyin = file;
    yyparse();
    fnc = FNC_builder::get().getFNC();
    fclose(file);
    return (fnc);
}