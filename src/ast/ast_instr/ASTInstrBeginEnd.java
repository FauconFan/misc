package src.ast.ast_instr;

import src.lexer_parser.Sym;
import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.AST;

public class ASTInstrBeginEnd implements ASTInstr
{
	private AST content;

	public ASTInstrBeginEnd(AST content)
	{
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
}
