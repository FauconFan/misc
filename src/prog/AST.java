package src.prog;

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