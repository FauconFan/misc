package src.tokens;

import src.lexer_parser.Sym;

public class OperatorToken extends Token
{
	private char op;

	public OperatorToken(Sym s, String match)
	{
		super(s);
		if (match.length() != 1)
		{
			throw new RuntimeException("SNA in OperatorToken Constructor");
		}
		this.op = match.charAt(0);
	}

	public char getOp()
	{
		return (this.op);
	}
}
