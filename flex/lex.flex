package src.lexer_parser;

import src.lexer_parser.tokens.ColorToken;
import src.lexer_parser.tokens.IdentifierToken;
import src.lexer_parser.tokens.NumberToken;
import src.lexer_parser.tokens.OperatorToken;
import src.lexer_parser.tokens.Token;
import src.lexer_parser.tokens.EqOpToken;
import src.lexer_parser.tokens.BoolOpToken;
import src.lexer_parser.tokens.CompareOpToken;

%%
%public
%class LexerFlex
%unicode
%type Token
%line
%column

%{
    public Token token(Sym type) {
        return new Token(type, yyline + 1, yycolumn + 1);
    }

    public NumberToken token(int value) {
        return new NumberToken(Sym.NUMBER, value, yyline + 1, yycolumn + 1);
    }

    public Token token(Sym type, String value) {
        if (type == Sym.IDENTIFIER)
        {
            return new IdentifierToken(type,value, yyline + 1, yycolumn + 1);
        }
        else if (type == Sym.OPERATOR)
        {
            return new OperatorToken(type,value, yyline + 1, yycolumn + 1);
        }
        else if (type == Sym.COLOR)
        {
            return new ColorToken(type,value, yyline + 1, yycolumn + 1);
        }
        else if (type == Sym.EQOP)
        {
            return new EqOpToken(type, value, yyline + 1, yycolumn + 1);
        }
        else if (type == Sym.BOOLOP)
        {
            return new BoolOpToken(type, value, yyline + 1, yycolumn + 1);
        }
        else if (type == Sym.COMPAREOP)
        {
            return new CompareOpToken(type, value, yyline + 1, yycolumn + 1);
        }
        System.err.println("SNA parsing in flex");
        return (null);
    }
%}

%yylexthrow{
	Exception, LexerException
%yylexthrow}

number = [0-9]+
string = [a-z][a-zA-Z_]*
blank = "\n" | "\r" | " " | "\t" | "\v" | "\f" 
operator = "+" | "-" | "*" | "/"
compNum = "<=" | ">=" | "<" | ">"
opBool = "&&" | "||"
eqOp = "==" | "!="
hex = [0-9A-F]
color = #{hex}{hex}{hex}{hex}{hex}{hex}

%%
{number}    		{return token(Integer.parseInt(yytext()));}
{color}				{return token(Sym.COLOR,yytext());}
{operator}			{return token(Sym.OPERATOR,yytext());}
{string}            {return token(Sym.IDENTIFIER, yytext());}
{eqOp}              {return token(Sym.EQOP, yytext());}
{opBool}            {return token(Sym.BOOLOP, yytext());}
{compNum}           {return token(Sym.COMPAREOP, yytext());}
","					{return token(Sym.COMMA);}
";"					{return token(Sym.SEMICOLON);}
"("             	{return token(Sym.LPAR);}
")"                 {return token(Sym.RPAR);}
"["                 {return token(Sym.LBRA);}
"]"                 {return token(Sym.RBRA);}
"True"              {return token(Sym.TRUE);}
"False"             {return token(Sym.FALSE);}
"Begin"				{return token(Sym.BEGIN);}
"End"				{return token(Sym.END);}
"While"				{return token(Sym.WHILE);}
"Do"				{return token(Sym.DO);}
"For"               {return token(Sym.FOR);}
"If"	            {return token(Sym.IF);}
"Elif"      		{return token(Sym.ELIF);}
"Then"      		{return token(Sym.THEN);}
"Else"      		{return token(Sym.ELSE);}
"Const"				{return token(Sym.CONST);}
"Var"				{return token(Sym.VAR);}
"="					{return token(Sym.EQUALS);}
"Exit"              {return token(Sym.EXIT);}
"DrawCircle"		{return token(Sym.DRAWCIRCLE);}
"FillCircle"		{return token(Sym.FILLCIRCLE);}
"DrawRect"			{return token(Sym.DRAWRECT);}
"FillRect"			{return token(Sym.FILLRECT);}
{blank}     		{}
[^]		            {throw new LexerException(yytext(), yyline + 1, yycolumn + 1);}
