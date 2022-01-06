package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

public class IdentifierToken extends Token
{
	private String value;

	public IdentifierToken(Sym c, String v, int line, int column)
	{
		super(c, line, column);
		this.value = v;
	}

	public String getValue()
	{
		return (value);
	}
}
