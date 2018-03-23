package src.ast;

import java.awt.Color;
import src.lexer_parser.Sym;
import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

import java.awt.Graphics2D;

public class ASTInstrExec extends ASTInstr
{
	private enum ASTInstrExecType
	{
		DRAWCIRCLE(3, 1),
		FILLCIRCLE(3, 1),
		DRAWRECT(4, 1),
		FILLRECT(4, 1);

		public final int nb_arg_int;
		public final int nb_arg_color;

		ASTInstrExecType(int nb_int, int nb_color)
		{
			this.nb_arg_int   = nb_int;
			this.nb_arg_color = nb_color;
		}
	}

	private final ASTInstrExecType mode;
	private final ASTExpr[] args;
	private final Color[] colors;

	public ASTInstrExec(Sym s, ASTExpr[] args, Color[] colors)
	{
		switch (s)
		{
		case DRAWCIRCLE: this.mode = ASTInstrExecType.DRAWCIRCLE; break;

		case FILLCIRCLE: this.mode = ASTInstrExecType.FILLCIRCLE; break;

		case DRAWRECT: this.mode = ASTInstrExecType.DRAWRECT; break;

		case FILLRECT: this.mode = ASTInstrExecType.FILLRECT; break;

		default: throw new RuntimeException("SNA ASTInstrExec Constructor");
		}
		if (args.length != this.mode.nb_arg_int || colors.length != this.mode.nb_arg_color)
		{
			throw new RuntimeException("SNA ASTInstrExec Constructor 2");
		}
		this.args   = args;
		this.colors = colors;
	}

	public void exec(Prog prog)
	{
		Graphics2D g2d;
		int x = 0;
		int y = 0;
		int r = 0;
		int width = 0;
		int height = 0;

		g2d = prog.getGraphics();

		g2d.setColor(colors[0]);
		switch (this.mode)
		{
			case DRAWCIRCLE :
				x = args[0].evalExpr(prog);
				y = args[1].evalExpr(prog);
				r = args[2].evalExpr(prog);
				g2d.drawOval(x, y, r, r);
				break ;
			case FILLCIRCLE :
				x = args[0].evalExpr(prog);
				y = args[1].evalExpr(prog);
				r = args[2].evalExpr(prog);
				g2d.fillOval(x, y, r, r);
				break ;
			case DRAWRECT :
				x = args[0].evalExpr(prog);
				y = args[1].evalExpr(prog);
				width = args[2].evalExpr(prog);
				height = args[3].evalExpr(prog);
				g2d.drawRect(x, y, width, height);
				break ;
			case FILLRECT :
				x = args[0].evalExpr(prog);
				y = args[1].evalExpr(prog);
				width = args[2].evalExpr(prog);
				height = args[3].evalExpr(prog);
				g2d.fillRect(x, y, width, height);
				break ;

			default :
				throw new RuntimeException("SNA ASTInstrExec Constructor");
		}
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		for (ASTExpr expr : args)
		{
			expr.checkSemantic(sa);
		}
	}

	public String toString()
	{
		return (this.mode.toString());
	}
}
