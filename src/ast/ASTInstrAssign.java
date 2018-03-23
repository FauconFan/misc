package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public class ASTInstrAssign extends ASTInstr
{
	private String identifier;
	private ASTExpr expr;

	public ASTInstrAssign(String identifier, ASTExpr expr)
	{
		this.identifier = identifier;
		this.expr       = expr;
	}

	public void exec(Prog prog)
	{
		int new_value;

		new_value = expr.evalExpr(prog);
		prog.setData(this.identifier, new_value);
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		sa.can_modify_var_in_registre(identifier);
		expr.checkSemantic(sa);
	}

	public String toString()
	{
		return ("ASTInstrAssign");
	}
}
