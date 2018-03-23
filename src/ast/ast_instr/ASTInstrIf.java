package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

// We accept that expr and follow can be null
public class ASTInstrIf implements ASTInstr
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

	public void exec(Prog prog)
	{
		if ((this.expr != null && this.expr.evalExpr(prog) != 0) == false)
		{
			this.instr.exec(prog);
		}
		if (this.follow != null)
			this.follow.exec(prog);
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
