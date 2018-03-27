package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_instr.ASTInstr;
import src.ast_rep.BlockASTLeaf;

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

	public BlockASTLeaf[] getChilds()
	{
		BlockASTLeaf[] res;
		int            len;

		len  = 0;
		len += (this.instr != null) ? 1 : 0;
		len += (this.next != null) ? 1 : 0;

		res = new BlockASTLeaf[len];
		if (len == 1)
		{
			res[0] = new BlockASTLeaf((this.instr != null) ? this.instr : this.next);
		}
		else if (len == 2)
		{
			res[0] = new BlockASTLeaf(this.instr);
			res[1] = new BlockASTLeaf(this.next);
		}
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
