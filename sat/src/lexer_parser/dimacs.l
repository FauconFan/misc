%{
    #include "dimacs.parser.hpp"
%}

%option noyywrap
%%
[ \t\n]             ;
"c ".*              ;
"c\n"               ;
[p]                 { return yytext[0]; }
"cnf"               { return CNF; }
"0"                 { return ZERO; }
-?[1-9]+[0-9]*      { yylval.ival = atoi(yytext); return INT; }
.                   ;

%%