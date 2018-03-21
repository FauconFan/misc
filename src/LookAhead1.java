package src;

import java.io.*;
import src.tokens.Token;

class LookAhead1
{
	/* Simulating a reader class for a stream of Token */

	private Token current;
	private LexerFlex lexer;

	public LookAhead1(LexerFlex l) throws Exception, IOException, LexerException
	{
		lexer   = l;
		current = lexer.yylex();
	}

	public boolean check(Sym s)
	{
		/* check whether the first character is of type s*/
		return (current.symbol() == s);
	}

	public void eat(Sym s) throws Exception
	{
		/* consumes a token of type s from the stream,
		 * exception when the contents does not start on s.   */
		if (!check(s))
		{
			throw new Exception("Token " + s + " expected...");
		}
		current = lexer.yylex();
	}

	public Token walkThrough() throws Exception
	{
		Token res;

		res = current;
		current = lexer.yylex();
		return (res);
	}

	public boolean isEmpty()
	{
		return (current == null);
	}
}
