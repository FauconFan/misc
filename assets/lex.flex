%%
%public
%class LexerFlex
%unicode
%type src.tokens.Token
%line
%column

%{
    public src.tokens.Token token(Sym type) {
        return new src.tokens.Token(type);
    }

    public src.tokens.NumberToken token(Sym type, int value) {
        return new src.tokens.NumberToken(type,value);
    }

    public src.tokens.Token token(Sym type, String value) {
        if (type == Sym.IDENTIFIER)
        {
            return new src.tokens.IdentifierToken(type,value);
        }
        else if (type == Sym.OPERATOR)
        {
            return new src.tokens.OperatorToken(type,value);
        }
        else if (type == Sym.COLOR)
        {
            return new src.tokens.ColorToken(type,value);
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
hex = [0-9A-F]
color = #{hex}{hex}{hex}{hex}{hex}{hex}

%%
{number}    		{return token(Sym.NUMBER,Integer.parseInt(yytext()));}
{color}				{return token(Sym.COLOR,yytext());}
{operator}			{return token(Sym.OPERATOR,yytext());}
{string}			{return token(Sym.IDENTIFIER, yytext());}
","					{return token(Sym.COMMA);}
";"					{return token(Sym.SEMICOLON);}
"("             	{return token(Sym.LPAR);}
")"                 {return token(Sym.RPAR);}
"Begin"				{return token(Sym.BEGIN);}
"End"				{return token(Sym.END);}
"While"				{return token(Sym.WHILE);}
"Do"				{return token(Sym.DO);}
"Done"				{return token(Sym.DONE);}
"If"	            {return token(Sym.IF);}
"Elif"      		{return token(Sym.ELIF);}
"Then"      		{return token(Sym.THEN);}
"Else"      		{return token(Sym.ELSE);}
"Const"				{return token(Sym.CONST);}
"Var"				{return token(Sym.VAR);}
"="					{return token(Sym.EQUALS);}
"DrawCircle"		{return token(Sym.DRAWCIRCLE);}
"FillCircle"		{return token(Sym.FILLCIRCLE);}
"DrawRect"			{return token(Sym.DRAWRECT);}
"FillRect"			{return token(Sym.FILLRECT);}
{blank}     		{}
[^]		            {throw new LexerException(yytext(), yyline, yycolumn);}
