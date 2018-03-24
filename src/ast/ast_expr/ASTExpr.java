package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

import java.awt.Point;

public interface ASTExpr
{
	public int evalExpr(Prog prog);
	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException;
	public Point begin();
	public Point end();
}
