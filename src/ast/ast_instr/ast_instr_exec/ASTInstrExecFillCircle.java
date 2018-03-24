package src.ast.ast_instr.ast_instr_exec;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;

import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

public class ASTInstrExecFillCircle extends ASTInstrExec
{
	public ASTInstrExecFillCircle(Point begin, Point end, ASTExpr[] e, Color[] c)
	{
		super(begin, end, e, c);
	}

	public void exec(Prog prog)
	{
		Graphics2D g2d;
		int        x;
		int        y;
		int        r;

		g2d = prog.getGraphics();
		g2d.setColor(this.colors[0]);
		x = this.args[0].evalExpr(prog);
		y = this.args[1].evalExpr(prog);
		r = this.args[2].evalExpr(prog);
		g2d.fillOval(x, y, r, r);
	}
}
