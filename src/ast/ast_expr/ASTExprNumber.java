package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

import java.awt.Point;

public class ASTExprNumber implements ASTExpr
{
	private final int number;
	private final Point begin, end;

	public ASTExprNumber(Point begin, Point end, int number)
	{
		this.number = number;
		this.begin  = begin;
		this.end    = end;
	}

	public int evalExpr(Prog prog)
	{
		return (this.number);
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		return;
	}

	public String toString()
	{
		return (Integer.toString(this.number));
	}

	public Point begin(){
		return begin;
	}

	public Point end(){
		return end;
	}
}
