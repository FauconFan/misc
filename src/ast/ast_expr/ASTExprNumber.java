package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public class ASTExprNumber implements ASTExpr
{
	private final int number;

	public ASTExprNumber(int number)
	{
		this.number = number;
	}

	public int evalExpr(Prog prog)
	{
		return (this.number);
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		return ;
	}

	public String toString()
	{
		return (Integer.toString(this.number));
	}
}