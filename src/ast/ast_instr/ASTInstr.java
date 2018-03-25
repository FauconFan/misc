package src.ast.ast_instr;

import src.prog.Prog;
import src.ast.ASTInterface;

import java.awt.Point;

public interface ASTInstr extends ASTInterface
{
	public void exec(Prog prog);
	public Point begin();
	public Point end();
}
