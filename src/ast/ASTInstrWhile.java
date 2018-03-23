package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;

public class ASTInstrWhile extends ASTInstr
{
	private ASTExpr expr;
	private ASTInstr content;

	public ASTInstrWhile(ASTExpr expr, ASTInstr content)
	{
		this.expr = expr;
		this.content = content;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		this.expr.checkSemantic(sa);
		this.content.checkSemantic(sa);
	}

	public String toString()
	{
		return ("ASTInstrWhile");
	}
}