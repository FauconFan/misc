package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.lexer_parser.LocatedException;

import java.awt.Point;

public class ASTInstrDecl extends ASTInstr
{
	private boolean is_cst;
	private String identifier;
	private ASTExpr expr;

	public ASTInstrDecl(Point begin, Point end, boolean is_cst, String identifier, ASTExpr expr)
	{
		super(begin, end);
		this.is_cst     = is_cst;
		this.identifier = identifier;
		this.expr       = expr;
	}

	public void exec(Prog prog)
	{
		prog.addData(this.identifier, this.expr.evalExpr(prog), this.is_cst);
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		expr.checkSemantic(sa);
		try{
			sa.add_in_registre(identifier, is_cst);
		}catch (Exception e) {
			throw new LocatedException("Invalid assignment ", begin(), end(), " : " + e.getMessage());
		}
	}

	public String getTag()
	{
		return ("Decl");
	}

	public String toTikz()
	{
		String res = "[ ";

		res += (this.is_cst) ? "Const" : "Var";
		res += "[ " + this.identifier + " ]";
		res += expr.toTikz();

		res += "]";
		return (res);
	}

	public String toString()
	{
		return ("ASTInstrDecl");
	}
}
