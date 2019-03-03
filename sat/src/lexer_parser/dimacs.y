%{
    #include "sat.hpp"

    extern int yylex();

    void yyerror(const char *s);
%}

%union {
    int ival;
}

%token CNF
%token ZERO

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
  std::cout << "EEK, parse error!  Message: " << s << std::endl;
}