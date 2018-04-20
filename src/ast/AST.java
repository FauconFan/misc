package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_instr.ASTInstr;

public class AST implements ASTInterface
{
	private final ASTInstr instr;
	private final AST next;

	public AST()
	{
		this(null, null);
	}

	public AST(ASTInstr instr, AST next)
	{
		this.instr = instr;
		this.next  = next;
	}

	public void exec(Prog prog)
	{
		if (instr != null)
		{
			instr.exec(prog);
		}
		if (next != null)
		{
			next.exec(prog);
		}
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		if (instr != null)
		{
			instr.checkSemantic(sa);
		}
		if (next != null)
		{
			next.checkSemantic(sa);
		}
	}

	public String getTag()
	{
		return ("AST");
	}

	public String toTikz()
	{
		String res = "[ AST ";

		if (instr != null)
		{
			res += this.instr.toTikz();
		}
		if (next != null)
		{
			res += this.next.toTikz();
		}
		res += "]";
		return (res);
	}

	public String toString()
	{
		if (instr == null&& next == null)
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
