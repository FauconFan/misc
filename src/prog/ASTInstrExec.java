package src.prog;

import java.awt.Color;
import src.lexer_parser.Sym;

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
			this.nb_arg_int = nb_int;
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
			case DRAWCIRCLE: this.mode = ASTInstrExecType.DRAWCIRCLE; break ;
			case FILLCIRCLE: this.mode = ASTInstrExecType.FILLCIRCLE; break ;
			case DRAWRECT: this.mode = ASTInstrExecType.DRAWRECT; break ;
			case FILLRECT: this.mode = ASTInstrExecType.FILLRECT; break ;
			default : throw new RuntimeException("SNA ASTInstrExec Constructor");
		}
		if (args.length != this.mode.nb_arg_int || colors.length != this.mode.nb_arg_color)
		{
			throw new RuntimeException("SNA ASTInstrExec Constructor 2");
		}
		this.args = args;
		this.colors = colors;
	}

	public String toString()
	{
		return (this.mode.toString());
	}
}