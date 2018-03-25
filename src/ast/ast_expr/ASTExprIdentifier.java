package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast_rep.BlockASTLeaf;
import src.prog.Prog;

import java.awt.Point;

public class ASTExprIdentifier implements ASTExpr
{
	private final String identifier;
	private final Point begin, end;

	public ASTExprIdentifier(Point begin, Point end, String identifier)
	{
		this.begin		= begin;
		this.end		= end;
		this.identifier = identifier;
	}

	public int evalExpr(Prog prog)
	{
		try{
			return (prog.getData(this.identifier));
		}catch(Exception e){
			String s = "Invalid variable or constant use ";
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
			sa.can_access_var_in_registre(this.identifier);
		}catch(Exception e){
			String s = "Invalid variable or constant use ";
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
		return (this.identifier);
	}

	public BlockASTLeaf[] getChilds()
	{
		return (new BlockASTLeaf[0]);
	}

	public Point begin(){
		return begin;
	}

	public Point end(){
		return end;
	}
}
