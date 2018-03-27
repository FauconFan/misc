package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast_rep.BlockASTLeaf;
import src.prog.Prog;
import src.lexer_parser.LocatedException;

import java.awt.Point;

public class ASTExprCalculus extends ASTExpr
{
	private final ASTExpr left;
	private final char op;
	private final ASTExpr right;

	public ASTExprCalculus(Point begin, Point end, ASTExpr left, char op, ASTExpr right)
	{
		super(begin, end);
		this.left  = left;
		this.op    = op;
		this.right = right;
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
		throw new LocatedException("Invalid operation ", begin(), end(), "");
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
}
