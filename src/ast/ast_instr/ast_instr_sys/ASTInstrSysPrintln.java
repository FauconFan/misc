package src.ast.ast_instr.ast_instr_sys;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.lexer_parser.LocatedException;
import src.ast.ast_instr.ASTInstr;

import java.awt.Point;

public class ASTInstrSysPrintln extends ASTInstr
{
	private String content;
	private ASTExpr expr;

	public ASTInstrSysPrintln(Point begin, Point end, String content)
	{
		super(begin, end);
		this.content = content;
		this.expr = null;
	}

	public ASTInstrSysPrintln(Point begin, Point end, ASTExpr expr)
	{
		super(begin, end);
		this.content = null;
		this.expr = expr;
	}

	public void exec(Prog prog)
	{
		if (content != null)
		{
			System.out.println(content);
		}
		else
		{
			System.out.println(Integer.toString(expr.evalExpr(prog)));
		}
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		if (expr != null)
		{
			expr.checkSemantic(sa);
		}
	}

	public String getTag()
	{
		return ("Println");
	}

	public String toTikz()
	{
		String res = "[Println ";

		res += "[ " + content + "]";
		res += "]";

		return (res);
	}
}
