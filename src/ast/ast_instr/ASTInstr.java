package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public interface ASTInstr
{
	public abstract void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException;
	public abstract void exec(Prog prog);
}
