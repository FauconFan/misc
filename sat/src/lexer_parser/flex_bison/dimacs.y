%{
    #include "sat.hpp"
    #include "dimacs.parser.hpp"

    #define YYINITDEPTH 100000
    #define YYMAXDEPTH 500000

    bool        yy_ok = true;
    bool        is_fnc;

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
%token SAT
%token ZERO
%token UNKNOWN

%token <ival> INT

%%

prog:
    header_cnf cnf footer { is_fnc = true; }
    | header_sat sat { is_fnc = false; }
    ;

header_cnf:
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
    | fnzero zero
    | fnzero zero endls
    ;

fnzero:
    cnf_var
    | cnf_var endls
    | fnzero cnf_var
    | fnzero cnf_var endls
    ;

cnf_var:
    INT { FNC_builder::get().addVar($1); }
    ;

zero:
    ZERO { FNC_builder::get().endOfClause(); }
    ;

footer:
    | '%' endls ZERO endls
    | '%' endls
    ;

endls:
    '\n'
    | endls '\n'
    ;

header_sat:
    'p' SAT INT endls {}
    ;

sat:
    begin_formula formula end_formula
    ;

begin_formula:
    '(' { Formula_builder::init_formula(); }
    ;

end_formula:
    ')'
    | ')' endls
    ;

formula:
    | '\n' formula
    | var_sat formula
    | begin_subformula formula end_subformula formula
    ;

begin_subformula:
    '-' '(' { Formula_builder::init_subformula_neg(); }
    | '*' '(' { Formula_builder::init_subformula_binop(And); }
    | '+' '(' { Formula_builder::init_subformula_binop(Or); }
    ;

end_subformula:
    ')' { Formula_builder::end_subformula(); }
    ;

var_sat:
    INT { Formula_builder::add_litt($1); }

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