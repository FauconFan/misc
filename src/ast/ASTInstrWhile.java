package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public class ASTInstrWhile extends ASTInstr
{
	private ASTExpr expr;
	private ASTInstr content;

	public ASTInstrWhile(ASTExpr expr, ASTInstr content)
	{
		this.expr    = expr;
		this.content = content;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		this.expr.checkSemantic(sa);
		this.content.checkSemantic(sa);
	}

	public void exec(Prog prog)
	{
		while (expr.evalExpr(prog) != 0)
		{
			this.content.exec(prog);
		}
	}

	public String toString()
	{
		return ("ASTInstrWhile");
	}
}
