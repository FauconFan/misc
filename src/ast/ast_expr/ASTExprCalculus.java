package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast_rep.BlockASTLeaf;
import src.prog.Prog;

import java.awt.Point;

public class ASTExprCalculus implements ASTExpr
{
	private final ASTExpr left;
	private final char op;
	private final ASTExpr right;
	private final Point begin, end;

	public ASTExprCalculus(Point begin, Point end, ASTExpr left, char op, ASTExpr right)
	{
		this.left  = left;
		this.op    = op;
		this.right = right;
		this.begin = begin;
		this.end   = end;
	}

	public int evalExpr(Prog prog)
	{
		int a;
		int b;

		a = this.left.evalExpr(prog);
		b = this.right.evalExpr(prog);
		if (this.op == '+')
		{
			return (a + b);
		}
		else if (this.op == '-')
		{
			return (a - b);
		}
		else if (this.op == '*')
		{
			return (a * b);
		}
		else if (this.op == '/')
		{
			return (a / b);
		}
		String s = "Invalid operation ";
		if (begin.x == end.x)
			if (begin.y == end. y)
				s += "lign " + begin.x + " at position " + begin.y;
			else
				s += "lign " + begin.x + " between position " + begin.y + " and position " + end.y;
		else
			s += "between lign " + begin.x + " position " + begin.y + " and lign " + end.x + " at position " + end.y;
		throw new RuntimeException(s);
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		this.left.checkSemantic(sa);
		this.right.checkSemantic(sa);
	}

	public String getTag()
	{
		return ("" + op);
	}

	public BlockASTLeaf[] getChilds()
	{
		BlockASTLeaf[] res = new BlockASTLeaf[2];

		res[0] = new BlockASTLeaf(left);
		res[1] = new BlockASTLeaf(right);
		return (res);
	}

	public Point begin(){
		return begin;
	}

	public Point end(){
		return end;
	}
}
