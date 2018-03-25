package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.ast_rep.BlockASTLeaf;

import java.awt.Point;

public class ASTInstrAssign implements ASTInstr
{
	private String identifier;
	private ASTExpr expr;
	private final Point begin, end;

	public ASTInstrAssign(Point begin, Point end, String identifier, ASTExpr expr)
	{
		this.begin		= begin;
		this.end 		= end;
		this.identifier = identifier;
		this.expr       = expr;
	}

	public void exec(Prog prog)
	{
		int new_value;

		new_value = expr.evalExpr(prog);
		try{
			prog.setData(this.identifier, new_value);
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

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		try{
			sa.can_modify_var_in_registre(identifier);
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
		expr.checkSemantic(sa);
	}

	public String getTag()
	{
		return ("Assign '='");
	}

	public BlockASTLeaf[] getChilds()
	{
		BlockASTLeaf[] res = new BlockASTLeaf[2];

		res[0] = new BlockASTLeaf(identifier);
		res[1] = new BlockASTLeaf(expr);
		return (res);
	}

	public Point begin(){
		return begin;
	}

	public Point end(){
		return end;
	}
}
