package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public class ASTExprCalculus implements ASTExpr
{
	private final ASTExpr left;
	private final char op;
	private final ASTExpr right;

	public ASTExprCalculus(ASTExpr left, char op, ASTExpr right)
	{
		this.left       = left;
		this.op         = op;
		this.right      = right;
	}

	public int evalExpr(Prog prog)
	{
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
		throw new RuntimeException("SNA evalExpr in ASTExprCalculus");
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		this.left.checkSemantic(sa);
		this.right.checkSemantic(sa);
	}

	public String toString()
	{
		return ("(" + this.left + " " + op + " " + this.right + ")");
	}
}