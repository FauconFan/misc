package src.tokens;

import src.lexer_parser.Sym;

public class OperatorToken extends Token
{
	private char op;

	public OperatorToken(Sym s, String match)
	{
		super(s);
		this.op = match.charAt(0);
	}

	public int apply(int a, int b)
	{
		if (op == '+')
			return (a + b);
		else if (op == '-')
			return (a - b);
		else if (op == '*')
			return (a * b);
		else if (op == '/')
			return (a / b);
		System.err.println("SNA apply OperatorToken");
		return (0);
	}
}
