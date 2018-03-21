package src.tokens;

import src.Sym;

public class NumberToken extends Token
{
	private int value;

	public NumberToken(Sym c, int n)
	{
		super(c);
		this.value = n;
	}

	public int value()
	{
		return (value);
	}
}