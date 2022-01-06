package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

public class StringToken extends Token
{
	private String value;

	public StringToken(Sym c, String value, int line, int column)
	{
		super(c, line, column);
		this.value = value;
	}

	public String getValue()
	{
		return (this.value);
	}
}
