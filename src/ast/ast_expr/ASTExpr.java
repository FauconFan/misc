package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public interface ASTExpr
{
	public int evalExpr(Prog prog);
	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException;
}
