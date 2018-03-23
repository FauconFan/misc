package src.ast.ast_instr.ast_instr_exec;

import java.awt.Color;
import java.awt.Graphics2D;

import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

public class ASTInstrExecFillRect extends ASTInstrExec
{
	public ASTInstrExecFillRect(ASTExpr[] e, Color[] c)
	{
		super(e, c);
	}

	public void exec(Prog prog)
	{
		Graphics2D g2d;
		int x;
		int y;
		int width;
		int height;

		g2d = prog.getGraphics();
		g2d.setColor(this.colors[0]);
		x = this.args[0].evalExpr(prog);
		y = this.args[1].evalExpr(prog);
		width = this.args[2].evalExpr(prog);
		height = this.args[3].evalExpr(prog);
		g2d.fillRect(x, y, width, height);
	}
}