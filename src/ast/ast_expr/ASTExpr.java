package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast.ASTInterface;
import src.prog.Prog;

import java.awt.Point;

public interface ASTExpr extends ASTInterface
{
	public int evalExpr(Prog prog);
	public Point begin();
	public Point end();
}
