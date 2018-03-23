package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

public abstract class ASTInstr
{
	public abstract void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException;
	public abstract void exec(Prog prog);
}
