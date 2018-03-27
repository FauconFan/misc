package src.ast.ast_instr;

import src.prog.Prog;
import src.ast.ASTInterface;

import java.awt.Point;

public abstract class ASTInstr implements ASTInterface
{
	private final Point begin, end;

	public abstract void exec(Prog prog);

	public ASTInstr(Point begin, Point end){
		this.begin = begin;
		this.end   = end;
	}

	public Point begin(){
		return begin;
	}

	public Point end(){
		return end;
	}
}
