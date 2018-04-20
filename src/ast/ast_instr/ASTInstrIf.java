package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

import java.awt.Point;

// We accept that expr and follow can be null
public class ASTInstrIf extends ASTInstr
{
	private ASTExpr expr;
	private ASTInstr instr;
	private ASTInstrIf follow;

	public ASTInstrIf(Point begin, Point end, ASTExpr expr, ASTInstr instr, ASTInstrIf follow)
	{
		super(begin, end);
		this.expr   = expr;
		this.instr  = instr;
		this.follow = follow;
	}

	public ASTInstrIf(Point begin, Point end, ASTInstr instr)
	{
		this(begin, end, null, instr, null);
	}

	public void exec(Prog prog)
	{
		if (this.expr == null || this.expr.evalExpr(prog) != 0)
		{
			this.instr.exec(prog);
		}
		else
		{
			if (this.follow != null)
			{
				this.follow.exec(prog);
			}
		}
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		if (this.expr != null)
		{
			expr.checkSemantic(sa);
		}
		this.instr.checkSemantic(sa);
		if (this.follow != null)
		{
			this.follow.checkSemantic(sa);
		}
	}

	public String getTag()
	{
		return ("If");
	}

	private String toTikzImbricated()
	{
		String res = "[ ";

		res += (expr != null) ? "Elif" : "Else";

		res += instr.toTikz();

		if (follow != null)
		{
			res += follow.toTikzImbricated();
		}

		res += "]";
		return (res);
	}

	public String toTikz()
	{
		String res = "[ If ";

		res += expr.toTikz();
		res += instr.toTikz();

		if (follow != null)
		{
			res += follow.toTikzImbricated();
		}

		res += "]";
		return (res);
	}
}
