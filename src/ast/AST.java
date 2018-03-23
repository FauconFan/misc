package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;

public class AST
{
	private final ASTInstr instr;
	private final AST next;

	public AST()
	{
		this.instr = null;
		this.next = null;
	}

	public AST(ASTInstr instr, AST next)
	{
		this.instr = instr;
		this.next = next;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		if (instr != null)
			instr.checkSemantic(sa);
		if (next != null)
			next.checkSemantic(sa);
	}

	public String toString()
	{
		if (instr == null && next == null)
		{
			return ("");
		}
		else if (next == null)
		{
			return (instr.toString());
		}
		return (instr + "\n" + next);
	}
}