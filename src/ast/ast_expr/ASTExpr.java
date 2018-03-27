package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast.ASTSuperClass;
import src.prog.Prog;

import java.awt.Point;

public abstract class ASTExpr extends ASTSuperClass
{
	public ASTExpr(Point begin, Point end)
	{
		super(begin, end);
	}

	public abstract int evalExpr(Prog prog);
}
