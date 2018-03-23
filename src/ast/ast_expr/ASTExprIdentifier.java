package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public class ASTExprIdentifier implements ASTExpr
{
	private final String identifier;

	public ASTExprIdentifier(String identifier)
	{
		this.identifier = identifier;
	}

	public int evalExpr(Prog prog)
	{
		return (prog.getData(this.identifier));
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		sa.can_access_var_in_registre(this.identifier);
	}

	public String toString()
	{
		return (this.identifier);
	}
}