package src.ast.ast_instr.ast_instr_sys;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.lexer_parser.LocatedException;
import src.ast.ast_instr.ASTInstr;

import java.awt.Point;

public class ASTInstrSysExit extends ASTInstr
{
	private ASTExpr expr;

	public ASTInstrSysExit(Point begin, Point end, ASTExpr expr)
	{
		super(begin, end);
		this.expr = expr;
	}

	public void exec(Prog prog)
	{
		int new_value;

		new_value = expr.evalExpr(prog);
		System.exit(new_value);
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		expr.checkSemantic(sa);
	}

	public String getTag()
	{
		return ("Exit");
	}

	public String toTikz()
	{
		String res = "[Exit]";

		return (res);
	}
}
