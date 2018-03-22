package src.tokens;

import src.lexer_parser.Sym;

public class NumberToken extends Token
{
	private int value;

	public NumberToken(Sym c, int n)
	{
		super(c);
		this.value = n;
	}

	public int getValue()
	{
		return (value);
	}
}