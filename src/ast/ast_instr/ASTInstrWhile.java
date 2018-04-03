package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

import java.awt.Point;

public class ASTInstrWhile extends ASTInstr
{
	private ASTExpr expr;
	private ASTInstr content;

	public ASTInstrWhile(Point begin, Point end, ASTExpr expr, ASTInstr content)
	{
		super(begin, end);
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

	public String getTag()
	{
		return ("While");
	}

	public String toTikz()
	{
		String res = "[ " + this.getTag();

		res += expr.toTikz();
		res += content.toTikz();
		res += "]";
		return res;
	}
}
