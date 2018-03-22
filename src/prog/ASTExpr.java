package src.prog;

public class ASTExpr
{
	private enum ASTExprType
	{
		NUMBER,
		IDENTIFIER,
		CALCULUS;
	}

	private final ASTExprType mode;

	// NUMBER
	private final int number;

	// IDENTIFIER
	private final String identifier;

	// CALCULUS
	private final ASTExpr left;
	private final char op;
	private final ASTExpr right;

	public ASTExpr(int number)
	{
		this.mode       = ASTExprType.NUMBER;
		this.number     = number;
		this.identifier = null;
		this.left       = null;
		this.op         = '0';
		this.right      = null;
	}

	public ASTExpr(String identifier)
	{
		this.mode       = ASTExprType.IDENTIFIER;
		this.number     = 0;
		this.identifier = identifier;
		this.left       = null;
		this.op         = '0';
		this.right      = null;
	}

	public ASTExpr(ASTExpr left, char op, ASTExpr right)
	{
		this.mode       = ASTExprType.CALCULUS;
		this.number     = 0;
		this.identifier = null;
		this.left       = left;
		this.op         = op;
		this.right      = right;
	}

	public int evalExpr()
	{
		switch (this.mode)
		{
		case NUMBER:
			return (this.number);
		case IDENTIFIER:
			System.err.println("Variables not implemented yet");
			return (0);
		case CALCULUS:
			int a;
			int b;

			a = this.left.evalExpr();
			b = this.right.evalExpr();
			if (this.op == '+')
				return (a + b);
			else if (this.op == '-')
				return (a - b);
			else if (this.op == '*')
				return (a * b);
			else if (this.op == '/')
				return (a / b);
			throw new RuntimeException ("SAN evalExpr in ASTExpr");
		default :
			throw new RuntimeException ("SAN evalExpr in ASTExpr");
		}
	}

	public String toString()
	{
		switch (this.mode)
		{
		case NUMBER:
			return (Integer.toString(this.number));

		case IDENTIFIER:
			return (this.identifier);

		case CALCULUS:
			return ("(" + this.left + " " + op + " " + this.right + ")");

		default: throw new RuntimeException("SNA toString ASTExpr");
		}
	}
}
