package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_bool.ASTBool;

import java.awt.Point;

public class ASTInstrWhile extends ASTInstr
{
	private ASTBool expr;
	private ASTInstr content;

	public ASTInstrWhile(Point begin, Point end, ASTBool expr, ASTInstr content)
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
		while (expr.evalExpr(prog))
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
		return (res);
	}
}
