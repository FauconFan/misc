package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public class ASTInstrDecl extends ASTInstr
{
	private boolean is_cst;
	private String identifier;
	private ASTExpr expr;

	public ASTInstrDecl(boolean is_cst, String identifier, ASTExpr expr)
	{
		this.is_cst     = is_cst;
		this.identifier = identifier;
		this.expr       = expr;
	}

	public void exec(Prog prog)
	{
		prog.addData(this.identifier, this.expr.evalExpr(prog), this.is_cst);
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		expr.checkSemantic(sa);
		sa.add_in_registre(identifier, is_cst);
	}

	public String toString()
	{
		return ("ASTInstrDecl");
	}
}
