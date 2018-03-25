package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.ast_rep.BlockASTLeaf;

import java.awt.Point;

public class ASTInstrDecl implements ASTInstr
{
	private boolean is_cst;
	private String identifier;
	private ASTExpr expr;
	private Point begin, end;

	public ASTInstrDecl(Point begin, Point end, boolean is_cst, String identifier, ASTExpr expr)
	{
		this.begin		= begin;
		this.end 		= end;
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
		}catch(Exception e){
			String s = "Invalid assignment ";
			if (begin.x == end.x)
				if (begin.y == end. y)
					s += "lign " + begin.x + " at position " + begin.y;
				else
					s += "lign " + begin.x + " between position " + begin.y + " and position " + end.y;
			else
				s += "between lign " + begin.x + " at position " + begin.y + " and lign " + end.x + " at position " + end.y;
			throw new RuntimeException(s + " : " + e.getMessage());
		}
	}

	public String getTag()
	{
		return ("Decl");
	}

	public BlockASTLeaf[] getChilds()
	{
		BlockASTLeaf[] res;
		String prefix;

		res = new BlockASTLeaf[2];
		prefix = (this.is_cst) ? "Const " : "Var ";
		res[0] = new BlockASTLeaf(prefix + identifier);
		res[1] = new BlockASTLeaf(expr);
		return (res);
	}

	public String toString()
	{
		return ("ASTInstrDecl");
	}

	public Point begin(){
		return begin;
	}

	public Point end(){
		return end;
	}
}
