package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast.ASTInterface;
import src.prog.Prog;

import java.awt.Point;

public abstract class ASTExpr implements ASTInterface
{
	private final Point begin, end;

	public ASTExpr(Point begin, Point end)
	{
		this.begin = begin;
		this.end   = end;
	}

	public abstract int evalExpr(Prog prog);

	public Point begin()
	{
		return (begin);
	}

	public Point end()
	{
		return (end);
	}
}
