%{
    #include "cimp.h"
    #include "cimp.parser.h"

    extern t_bool lex_par_ok;

    static int handle_num(const char *);
%}

%option noyywrap

DIGIT       [0-9]
LETTER      [a-zA-Z]

NUMBER      \-?{DIGIT}+
WORD        ({LETTER}|{DIGIT}|\.|\_|\-)+
PT_FOLDER   (\.\/|\.\.\/|{WORD}\/)
PATH        (\/)?{PT_FOLDER}+{WORD}?

%%

[()]                { return (yytext[0]);}
{NUMBER}            { yylval.numval = handle_num(yytext); return NUM_B; }
{PATH}              { yylval.strval = yytext; return PATH_B; }
{WORD}              { yylval.strval = yytext; return WORD_B; }

[ \t\n\r]           ;

.                   { lex_par_ok = FALSE; printf("UNK(\"%s\")\n", yytext); }

%%

static int  handle_num(const char * str) {
    int num;

    if (safe_strtol10(str, NULL, &num) == FALSE) {
        lex_par_ok = FALSE;
    }
    return (num);
}

void    _yy_set_buffer(const char *str) {
    yy_delete_buffer(YY_CURRENT_BUFFER);
    yy_switch_to_buffer(yy_scan_string(str));
}