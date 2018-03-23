package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;

public abstract class ASTInstr
{
	public abstract void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException;
}
