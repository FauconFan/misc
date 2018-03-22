package src.prog;

public class ASTInstrWhile extends ASTInstr
{
	private ASTExpr expr;
	private ASTInstr content;

	public ASTInstrWhile(ASTExpr expr, ASTInstr content)
	{
		this.expr = expr;
		this.content = content;
	}

	public String toString()
	{
		return ("ASTInstrWhile");
	}
}