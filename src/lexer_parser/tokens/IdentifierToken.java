package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

public class IdentifierToken extends Token
{
	private String value;

	public IdentifierToken(Sym c, String v, int lign, int column)
	{
		super(c, lign, column);
		this.value = v;
	}

	public String getValue()
	{
		return (value);
	}
}
