package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

import java.awt.Point;

public class ASTInstrWhile implements ASTInstr
{
	private ASTExpr expr;
	private ASTInstr content;
	private Point begin, end;

	public ASTInstrWhile(Point begin, Point end, ASTExpr expr, ASTInstr content)
	{
		this.begin	 = begin;
		this.end 	 = end;
		this.expr    = expr;
		this.content = content;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		this.expr.checkSemantic(sa);
		this.content.checkSemantic(sa);
	}

	public void exec(Prog prog)
	{
		while (expr.evalExpr(prog) != 0)
		{
			this.content.exec(prog);
		}
	}

	public String toString()
	{
		return ("ASTInstrWhile");
	}

	public Point begin(){
		return begin;
	}

	public Point end(){
		return end;
	}
}