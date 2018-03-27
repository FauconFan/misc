package src.ast.ast_instr;

import src.lexer_parser.Sym;
import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.AST;
import src.ast_rep.BlockASTLeaf;

import java.awt.Point;

public class ASTInstrBeginEnd extends ASTInstr
{
	private AST content;

	public ASTInstrBeginEnd(Point begin, Point end, AST content)
	{
		super(begin, end);
		this.content = content;
	}

	public void exec(Prog prog)
	{
		prog.incremente();
		content.exec(prog);
		prog.decremente();
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		sa.incremente();
		content.checkSemantic(sa);
		sa.decremente();
	}

	public String toString()
	{
		String  in;
		boolean hasLastNL = false;

		in        = content.toString();
		hasLastNL = (in.charAt(in.length() - 1) == '\n');
		if (hasLastNL)
		{
			in = in.substring(0, in.length() - 1);
		}
		in = in.replace("\n", "\n\t");
		if (hasLastNL)
		{
			in += "\n";
		}
		return ("Begin ASTInstrBeginEnd" + "\n\t" + in + "End ASTInstrBeginEnd");
	}

	public String getTag()
	{
		return ("Begin - End");
	}

	public BlockASTLeaf[] getChilds()
	{
		BlockASTLeaf[] res = new BlockASTLeaf[1];

		res[0] = new BlockASTLeaf(this.content);
		return (res);
	}
}
