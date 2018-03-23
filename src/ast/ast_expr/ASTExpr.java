package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

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

	public int evalExpr(Prog prog)
	{
		switch (this.mode)
		{
		case NUMBER:
			return (this.number);

		case IDENTIFIER:
			return (prog.getData(this.identifier));

		case CALCULUS:
			int a;
			int b;

			a = this.left.evalExpr(prog);
			b = this.right.evalExpr(prog);
			if (this.op == '+')
			{
				return (a + b);
			}
			else if (this.op == '-')
			{
				return (a - b);
			}
			else if (this.op == '*')
			{
				return (a * b);
			}
			else if (this.op == '/')
			{
				return (a / b);
			}
			throw new RuntimeException("SNA evalExpr in ASTExpr");

		default:
			throw new RuntimeException("SNA evalExpr in ASTExpr");
		}
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		switch (this.mode)
		{
		case NUMBER:
			return;

		case IDENTIFIER:
			sa.can_access_var_in_registre(this.identifier);
			return;

		case CALCULUS:
			this.left.checkSemantic(sa);
			this.right.checkSemantic(sa);
			return;

		default:
			throw new RuntimeException("SNA checkSemantic");
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
