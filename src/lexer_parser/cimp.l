%{
    #include "cimp.h"

    static t_li_token   * li_token = NULL;
    static t_bool       lex_ok = TRUE;
%}

%option noyywrap

DIGIT       [0-9]
LETTER      [a-zA-Z]
NUMBER      {DIGIT}+
WORD        ({LETTER}|{DIGIT}|\.)+
PT_FOLDER   (\.\/|\.\.\/|{WORD}\/)
PATH        (\/)?{PT_FOLDER}+{WORD}?

%%

[ \t\n\r]           ;

{NUMBER}            { li_token_add(li_token, token_num(yytext)); }
{PATH}              { li_token_add(li_token, token_path(yytext)); }
{WORD}              { li_token_add(li_token, token_word(yytext)); }
.                   { lex_ok = FALSE; printf("UNK(\"%s\")\n", yytext); }

%%

t_li_token    *scan_string(const char *str) {
    li_token = li_token_alloc();
    lex_ok = TRUE;
    yy_delete_buffer(YY_CURRENT_BUFFER);
    yy_switch_to_buffer(yy_scan_string(str));
    yylex();
    if (lex_ok == FALSE) {
        li_token_free(li_token);
        printf("Some unexpected characters appeared : fail to lex properly...\n");
        return (NULL);
    }
    return (li_token);
}