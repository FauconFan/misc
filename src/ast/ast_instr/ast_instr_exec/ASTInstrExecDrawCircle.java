package src.ast.ast_instr.ast_instr_exec;

import java.awt.Color;
import java.awt.Graphics2D;

import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

public class ASTInstrExecDrawCircle extends ASTInstrExec
{
	public ASTInstrExecDrawCircle(ASTExpr[] e, Color[] c)
	{
		super(e, c);
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
		g2d.drawOval(x, y, r, r);
	}
}
