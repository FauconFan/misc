package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast_rep.BlockASTLeaf;

public interface ASTInterface
{
	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException;
	public String getTag();

	public BlockASTLeaf[] getChilds();
}
