package src.lexer_parser;

import java.io.*;
import src.lexer_parser.tokens.Token;

public class LookAhead1
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
		return (current.symbol() == s);
	}

	public void eat(Sym s) throws Exception
	{
		if (check(s) == false)
		{
			throw new Exception("Token " + s + " expected line " + current.getLign() + " position " + current.getColumn() + ", found " + current);
		}
		current = lexer.yylex();
	}

	public Token pop(Sym s) throws Exception
	{
		Token ret;

		if (check(s) == false)
		{
			throw new Exception("Token " + s + " expected line " + current.getLign() + " position " + current.getColumn() + ", found " + current);
		}
		ret     = current;
		current = lexer.yylex();
		return (ret);
	}

	public Token walkThrough() throws Exception
	{
		Token res;

		res     = current;
		current = lexer.yylex();
		return (res);
	}

	public boolean isEmpty()
	{
		return (current == null);
	}

	public int getLign()
	{
		return (current.getLign());
	}

	public int getColumn()
	{
		return (current.getColumn());
	}
}
