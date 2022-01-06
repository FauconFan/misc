package src.ast.ast_instr.ast_instr_exec;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.ast.ast_instr.ASTInstr;
import src.ast.ASTInterface;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;

public abstract class ASTInstrExec extends ASTInstr
{
	protected final ASTExpr[] args;
	protected final Color[] colors;

	public ASTInstrExec(Point begin, Point end, ASTExpr[] args, Color[] colors)
	{
		super(begin, end);
		this.args   = args;
		this.colors = colors;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		for (ASTExpr expr : args)
		{
			expr.checkSemantic(sa);
		}
	}

	public abstract String getTag();

	public String toTikz()
	{
		String res  = "[ " + this.getTag();
		String data = "0123456789ABCDEF";

		for (ASTExpr expr : this.args)
		{
			res += expr.toTikz();
		}
		for (Color color : this.colors)
		{
			String str = "";

			str += data.charAt(color.getRed() / 16);
			str += data.charAt(color.getRed() % 16);
			str += data.charAt(color.getGreen() / 16);
			str += data.charAt(color.getGreen() % 16);
			str += data.charAt(color.getBlue() / 16);
			str += data.charAt(color.getBlue() % 16);
			res += "[ " + str + " ] ";
		}
		res += "]";
		return (res);
	}
}
