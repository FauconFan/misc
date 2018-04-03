package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;

public interface ASTInterface
{
	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException;
	public String toTikz();
}