package src.prog;

public class ASTInstrIf extends ASTInstr
{
	private ASTExpr expr;
	private ASTInstr instr;
	private ASTInstrIf follow;

	public ASTInstrIf(ASTExpr expr, ASTInstr instr, ASTInstrIf follow)
	{
		this.expr = expr;
		this.instr = instr;
		this.follow = follow;
	}

	public ASTInstrIf(ASTInstr instr)
	{
		this.expr = null;
		this.instr = instr;
		this.follow = null;
	}

	public String toString()
	{
		return ("ASTInstrIf");
	}
}