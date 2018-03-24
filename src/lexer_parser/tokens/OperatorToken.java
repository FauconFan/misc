package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

public class OperatorToken extends Token
{
	private char op;

	public OperatorToken(Sym s, String match, int lign, int column)
	{
		super(s, lign, column);
		this.op = match.charAt(0);
		if (match.length() != 1 || (op != '+' && op != '-' && op != '*' && op != '/'))
		{
			throw new RuntimeException("Invalid operation lign " + lign + " at position " + column);
		}
	}

	public char getOp()
	{
		return (this.op);
	}
}
