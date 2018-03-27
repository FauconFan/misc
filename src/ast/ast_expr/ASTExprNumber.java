package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast_rep.BlockASTLeaf;
import src.prog.Prog;

import java.awt.Point;

public class ASTExprNumber extends ASTExpr
{
	private final int number;

	public ASTExprNumber(Point begin, Point end, int number)
	{
		super(begin, end);
		this.number = number;
	}

	public int evalExpr(Prog prog)
	{
		return (this.number);
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		return;
	}

	public String getTag()
	{
		return (Integer.toString(this.number));
	}

	public BlockASTLeaf[] getChilds()
	{
		return (new BlockASTLeaf[0]);
	}
}
