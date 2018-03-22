package src.tokens;

import src.lexer_parser.Sym;

public class ColorToken extends Token
{
	private String value;

	public ColorToken(Sym c, String v)
	{
		super(c);
		this.value = v;
	}

	public String value()
	{
		return (value);
	}
}
