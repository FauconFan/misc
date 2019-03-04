%{
    #include "sat.hpp"

    extern int yylex();
    extern int lexer_line_num;

    void yyerror(const char *s);
%}

%error-verbose

%union {
    int ival;
}

%token CNF
%token ZERO
%token UNKNOWN

%token <ival> INT


%%

prog:
    header cnf
    ;

header:
    'p' CNF INT INT {
        FNC_builder::get().setNbVar($3);
        FNC_builder::get().setNbClause($4);
    }
    ;

cnf:
    cnf_pre formule
    | cnf_pre
    | formule
    ;

cnf_pre:
    cnf ZERO { FNC_builder::get().endOfClause(); }
    ;

formule:
    formule var
    | var
    ;

var:
    INT { FNC_builder::get().addVar($1); }

%%

void yyerror(const char *s) {
  std::cout
    << "Parser error (Line " << lexer_line_num << "):" << std::endl
    << "\t" << s << std::endl;
}