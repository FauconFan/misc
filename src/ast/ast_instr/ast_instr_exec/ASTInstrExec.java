package src.ast.ast_instr.ast_instr_exec;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.ast.ast_instr.ASTInstr;
import src.ast.ASTInterface;
import src.ast_rep.BlockASTLeaf;

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

	public BlockASTLeaf[] getChilds()
	{
		BlockASTLeaf[] res;
		String         data = "0123456789ABCDEF";

		res = new BlockASTLeaf[args.length + colors.length];
		for (int i = 0; i < args.length; i++)
		{
			res[i] = new BlockASTLeaf(args[i]);
		}
		for (int i = 0; i < colors.length; i++)
		{
			String str = "";

			str += data.charAt(colors[i].getRed() / 16);
			str += data.charAt(colors[i].getRed() % 16);
			str += data.charAt(colors[i].getGreen() / 16);
			str += data.charAt(colors[i].getGreen() % 16);
			str += data.charAt(colors[i].getBlue() / 16);
			str += data.charAt(colors[i].getBlue() % 16);
			res[i + args.length] = new BlockASTLeaf(str);
		}
		return (res);
	}
}
