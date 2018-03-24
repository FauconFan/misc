package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

public class NumberToken extends Token
{
	private int value;

	public NumberToken(Sym c, int n, int lign, int column)
	{
		super(c, lign, column);
		this.value = n;
	}

	public int getValue()
	{
		return (value);
	}
}
