package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.lexer_parser.LocatedException;

import java.awt.Point;

public class ASTInstrAssign extends ASTInstr
{
	private String identifier;
	private ASTExpr expr;

	public ASTInstrAssign(Point begin, Point end, String identifier, ASTExpr expr)
	{
		super(begin, end);
		this.identifier = identifier;
		this.expr       = expr;
	}

	public void exec(Prog prog)
	{
		int new_value;

		new_value = expr.evalExpr(prog);
		try{
			prog.setData(this.identifier, new_value);
		}catch (Exception e) {
			throw new LocatedException("Invalid assignment ", begin(), end(), " : " + e.getMessage());
		}
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		try{
			sa.can_modify_var_in_registre(identifier);
		}catch (Exception e) {
			throw new LocatedException("Invalid assignment ", begin(), end(), " : " + e.getMessage());
		}
		expr.checkSemantic(sa);
	}

	public String getTag()
	{
		return ("Assign '='");
	}

	public String toTikz()
	{
		String res = "[ Assign '=' ";

		res += "[ " + this.identifier + " ]";
		res += expr.toTikz();

		res += "]";
		return (res);
	}
}
