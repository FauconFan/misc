%{
    #include "sat.hpp"
    #include "dimacs.parser.hpp"

    bool        yy_ok = true;

    extern int yylex();

    extern std::vector<std::string>    buff_lines_yyin;

    void yyerror(const char *s);
%}

%error-verbose
%locations

%union {
    int ival;
}

%token CNF
%token ZERO
%token UNKNOWN

%token <ival> INT

%%

prog:
    header cnf footer
    | error cnf footer
    ;

header:
    'p' CNF INT INT endls {
        FNC_builder::get().setNbVar($3);
        FNC_builder::get().setNbClause($4);
    }
    ;

cnf:
    fnzero
    | fzero
    | fzero cnf
    ;

fzero:
    zero
    | zero endls
    | var fzero
    | var endls fzero
    ;

fnzero:
    var
    | var endls
    | var fnzero
    | var endls fnzero
    ;

var:
    INT { FNC_builder::get().addVar($1); }
    ;

zero:
    ZERO { FNC_builder::get().endOfClause(); }
    ;

footer:
    | '%' endls ZERO endls
    ;

endls:
    '\n'
    | endls '\n'

%%

void yyerror(const char *s) {
    const std::string & line = buff_lines_yyin[yylloc.first_line - 1];
    std::string prefix = " Line " + std::to_string(yylloc.first_line) + " | ";

    std::cout
        << "Parser error (Line " << yylloc.first_line << ", Column " << yylloc.first_column << "):"
        << " " << s << "\n";
    std::cout << prefix << line << "\n";
    for (size_t i = 0; i < prefix.size(); ++i)
        std::cout << ".";
    for (size_t i = 0; i < line.size(); ++i)
        std::cout << (i == yylloc.first_column - 1 ? '^' : '.');
    if (yylloc.first_column > line.size()) {
        for (size_t i = line.size(); i < yylloc.first_column - 1; ++i)
            std::cout << '.';
        std::cout << '^';
    }
    std::cout << "\n";
    yy_ok = false;
}