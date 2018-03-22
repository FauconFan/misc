package src.tokens;

import src.lexer_parser.Sym;

public class IdentifierToken extends Token
{
	private String value;

	public IdentifierToken(Sym c, String v)
	{
		super(c);
		this.value = v;
	}

	public String getValue()
	{
		return (value);
	}
}