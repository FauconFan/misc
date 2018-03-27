package src.ast.ast_instr;

import src.prog.Prog;
import src.ast.ASTSuperClass;

import java.awt.Point;

public abstract class ASTInstr extends ASTSuperClass
{
	public ASTInstr(Point begin, Point end)
	{
		super(begin, end);
	}

	public abstract void exec(Prog prog);
}
