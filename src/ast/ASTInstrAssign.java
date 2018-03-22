package src.ast;

public class ASTInstrAssign extends ASTInstr
{
	private String identifier;
	private ASTExpr expr;

	public ASTInstrAssign(String identifier, ASTExpr expr)
	{
		this.identifier = identifier;
		this.expr = expr;
	}

	public String toString()
	{
		return ("ASTInstrAssign");
	}
}