%{
    #include <string>
    #include "dimacs.parser.hpp"

    static void update_loc(){
        static int curr_line = 1;
        static int curr_col  = 1;

        yylloc.first_line   = curr_line;
        yylloc.first_column = curr_col;

        for (size_t i = 0; i < yyleng; ++i) {
            if (yytext[i] == '\n'){
                curr_line++;
                curr_col = 1;
            } else {
                curr_col++;
            }
        }

        yylloc.last_line   = curr_line;
        yylloc.last_column = curr_col - 1;
    }

    #define YY_USER_ACTION update_loc();
%}

%option noyywrap

%%
[ \t]*              ;
[p\n%]              { return yytext[0]; }
"cnf"               { return CNF; }
"0"                 { return ZERO; }
-?[1-9]+[0-9]*      { yylval.ival = atoi(yytext); return INT; }
"c ".*"\n"          ;
"c\n"               ;
.                   { return UNKNOWN; }

%%