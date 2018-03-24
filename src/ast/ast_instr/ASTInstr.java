package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

import java.awt.Point;

public interface ASTInstr
{
	public void exec(Prog prog);
	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException;
	public Point begin();
	public Point end();
}
