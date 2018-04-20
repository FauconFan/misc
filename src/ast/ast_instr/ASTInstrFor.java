package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

import java.awt.Point;

public class ASTInstrFor extends ASTInstr
{
	ASTInstr first;
	ASTExpr condition;
	ASTInstr eachLoop;
	ASTInstr content;

	public ASTInstrFor(Point begin, Point end, ASTInstr first, ASTExpr condition, ASTInstr eachLoop, ASTInstr content)
	{
		super(begin, end);
		this.first = first;
		this.condition = condition;
		this.eachLoop = eachLoop;
		this.content = content;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		sa.incremente();
		this.first.checkSemantic(sa);
		this.condition.checkSemantic(sa);
		this.eachLoop.checkSemantic(sa);
		this.content.checkSemantic(sa);
		sa.decremente();
	}

	public void exec(Prog prog)
	{
		prog.incremente();
		this.first.exec(prog);
		while (condition.evalExpr(prog) != 0)
		{
			this.content.exec(prog);
			this.eachLoop.exec(prog);
		}
		prog.decremente();
	}

	public String getTag()
	{
		return ("For");
	}

	public String toTikz()
	{
		String res = "[ " + this.getTag();

		res += first.toTikz();
		res += condition.toTikz();
		res += eachLoop.toTikz();
		res += content.toTikz();
		res += "]";
		return res;
	}
}
