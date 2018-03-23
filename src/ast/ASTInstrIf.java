package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;

public class ASTInstrIf extends ASTInstr
{
	private ASTExpr expr;
	private ASTInstr instr;
	private ASTInstrIf follow;

	public ASTInstrIf(ASTExpr expr, ASTInstr instr, ASTInstrIf follow)
	{
		this.expr   = expr;
		this.instr  = instr;
		this.follow = follow;
	}

	public ASTInstrIf(ASTInstr instr)
	{
		this.expr   = null;
		this.instr  = instr;
		this.follow = null;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		if (this.expr != null)
		{
			expr.checkSemantic(sa);
		}
		this.instr.checkSemantic(sa);
		if (this.follow != null)
		{
			this.follow.checkSemantic(sa);
		}
	}

	public String toString()
	{
		return ("ASTInstrIf");
	}
}
