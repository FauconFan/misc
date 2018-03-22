package src.tokens;

import src.lexer_parser.Sym;

public class Token
{
	protected Sym symbol;

	public Token(Sym s)
	{
		symbol = s;
	}

	public Sym symbol()
	{
		return (this.symbol);
	}

	public String toString()
	{
		return ("Symbol : " + this.symbol);
	}
}
