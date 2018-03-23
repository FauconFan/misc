package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;

public class ASTInstrAssign extends ASTInstr
{
	private String identifier;
	private ASTExpr expr;

	public ASTInstrAssign(String identifier, ASTExpr expr)
	{
		this.identifier = identifier;
		this.expr = expr;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		sa.verify_if_present_in_registre(identifier, true);
		expr.checkSemantic(sa);
	}

	public String toString()
	{
		return ("ASTInstrAssign");
	}
}