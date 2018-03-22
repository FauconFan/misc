package src.ast;

public class ASTInstrDecl extends ASTInstr
{
	private boolean is_cst;
	private String identifier;
	private ASTExpr expr;

	public ASTInstrDecl(boolean is_cst, String identifier, ASTExpr expr)
	{
		this.is_cst = is_cst;
		this.identifier = identifier;
		this.expr = expr;
	}

	public String toString()
	{
		return ("ASTInstrDecl");
	}
}