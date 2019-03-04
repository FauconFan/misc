%{
    #include "dimacs.parser.hpp"

    int lexer_line_num = 1;
%}

%option noyywrap
%%
[ \t]               ;
[\n]                { lexer_line_num++; }
[p]                 { return yytext[0]; }
"cnf"               { return CNF; }
"0"                 { return ZERO; }
-?[1-9]+[0-9]*      { yylval.ival = atoi(yytext); return INT; }
"c ".*              ;
"c"                 ;
.                   { return UNKNOWN; }

%%