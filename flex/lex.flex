package src.lexer_parser;

import src.lexer_parser.tokens.*;

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

    public StringToken stringToken(String value, char toEscape) {
        String finalStr = "";

        for (int i = 1; i < value.length() - 1; i++)
        {
            if (value.charAt(i) == '\\' && i < value.length() - 2)
            {
                if (value.charAt(i + 1) == 'b')
                {
                    finalStr += '\b';
                }
                else if (value.charAt(i + 1) == 't')
                {
                    finalStr += '\t';
                }
                else if (value.charAt(i + 1) == 'n')
                {
                    finalStr += '\n';
                }
                else if (value.charAt(i + 1) == 'f')
                {
                    finalStr += '\f';
                }
                else if (value.charAt(i + 1) == 'r')
                {
                    finalStr += '\r';
                }
                else if (value.charAt(i + 1) == toEscape)
                {
                    finalStr += toEscape;
                }
                else
                {
                    finalStr += value.charAt(i + 1);
                }
                i++;
            }
            else
            {
                finalStr += value.charAt(i);
            }
        }
        return new StringToken(Sym.STRING, finalStr, yyline + 1, yycolumn + 1);
    }
%}

%yylexthrow{
    Exception, LexerException
%yylexthrow}

number = [0-9]+
identifier = [a-z][a-zA-Z_]*
blank = "\n" | "\r" | " " | "\t" | "\v" | "\f" 
operator = "+" | "-" | "*" | "/"
compNum = "<=" | ">=" | "<" | ">" | "==" | "!="
opBool = "&&" | "||"
hex = [0-9A-F]
color = #{hex}{hex}{hex}{hex}{hex}{hex}
string_simple = \'(\\.|[^\'\\])*\'
string_double = \"(\\.|[^\"\\])*\"

%%
{number}                      {return token(Integer.parseInt(yytext()));}
{color}                       {return token(Sym.COLOR,yytext());}
{operator}                    {return token(Sym.OPERATOR,yytext());}
{identifier}                  {return token(Sym.IDENTIFIER, yytext());}
{opBool}                      {return token(Sym.BOOLOP, yytext());}
{compNum}                     {return token(Sym.COMPAREOP, yytext());}
{string_simple}               {return stringToken(yytext(), '\'');}
{string_double}               {return stringToken(yytext(), '\"');}
","                           {return token(Sym.COMMA);}
";"                           {return token(Sym.SEMICOLON);}
"("                           {return token(Sym.LPAR);}
")"                           {return token(Sym.RPAR);}
"["                           {return token(Sym.LBRA);}
"]"                           {return token(Sym.RBRA);}
"True"                        {return token(Sym.TRUE);}
"False"                       {return token(Sym.FALSE);}
"Begin"                       {return token(Sym.BEGIN);}
"End"                         {return token(Sym.END);}
"While"                       {return token(Sym.WHILE);}
"Do"                          {return token(Sym.DO);}
"For"                         {return token(Sym.FOR);}
"If"                          {return token(Sym.IF);}
"Elif"                        {return token(Sym.ELIF);}
"Then"                        {return token(Sym.THEN);}
"Else"                        {return token(Sym.ELSE);}
"Const"                       {return token(Sym.CONST);}
"Var"                         {return token(Sym.VAR);}
"="                           {return token(Sym.EQUALS);}
"Exit"                        {return token(Sym.EXIT);}
"Println"                     {return token(Sym.PRINTLN);}
"DrawCircle"                  {return token(Sym.DRAWCIRCLE);}
"FillCircle"                  {return token(Sym.FILLCIRCLE);}
"DrawRect"                    {return token(Sym.DRAWRECT);}
"FillRect"                    {return token(Sym.FILLRECT);}
{blank}                       {}
[^]                           {throw new LexerException(yytext(), yyline + 1, yycolumn + 1);}
