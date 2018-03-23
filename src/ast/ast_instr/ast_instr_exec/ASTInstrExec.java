package src.ast.ast_instr.ast_instr_exec;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.ast.ast_instr.ASTInstr;

import java.awt.Color;
import java.awt.Graphics2D;

public abstract class ASTInstrExec implements ASTInstr
{
	protected final ASTExpr[] args;
	protected final Color[] colors;

	public ASTInstrExec(ASTExpr[] args, Color[] colors)
	{
		this.args = args;
		this.colors = colors;
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		for (ASTExpr expr : args)
		{
			expr.checkSemantic(sa);
		}
	}
}
