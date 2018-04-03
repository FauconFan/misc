package src.ast.ast_instr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;
import src.ast_rep.BlockASTLeaf;

import java.awt.Point;

// We accept that expr and follow can be null
public class ASTInstrIf extends ASTInstr
{
	private ASTExpr expr;
	private ASTInstr instr;
	private ASTInstrIf follow;

	public ASTInstrIf(Point begin, Point end, ASTExpr expr, ASTInstr instr, ASTInstrIf follow)
	{
		super(begin, end);
		this.expr   = expr;
		this.instr  = instr;
		this.follow = follow;
	}

	public ASTInstrIf(Point begin, Point end, ASTInstr instr)
	{
		this(begin, end, null, instr, null);
	}

	public void exec(Prog prog)
	{
		if (this.expr == null || this.expr.evalExpr(prog) != 0)
		{
			this.instr.exec(prog);
		}
		else
		{	
			if (this.follow != null)
			{
				this.follow.exec(prog);
			}
		}
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		if (this.expr != null)
		{
			expr.checkSemantic(sa);
		}
		this.instr.checkSemantic(sa);
		if (this.follow != null)
		{
			this.follow.checkSemantic(sa);
		}
	}

	public String getTag()
	{
		return ("If");
	}

	public BlockASTLeaf[] getChilds()
	{
		BlockASTLeaf[] res;
		int            len;

		len  = 0;
		len += (this.expr != null) ? 1 : 0;
		len += (this.instr != null) ? 1 : 0;
		len += (this.follow != null) ? 1 : 0;

		res = new BlockASTLeaf[len];
		if (len == 1)
		{
			if (this.expr != null)
			{
				res[0] = new BlockASTLeaf(this.expr);
			}
			else if (this.instr != null)
			{
				res[0] = new BlockASTLeaf(this.instr);
			}
			else
			{
				res[0] = new BlockASTLeaf(this.follow);
			}
		}
		else if (len == 2)
		{
			if (this.expr == null)
			{
				res[0] = new BlockASTLeaf(this.instr);
				res[1] = new BlockASTLeaf(this.follow);
			}
			else if (this.instr == null)
			{
				res[0] = new BlockASTLeaf(this.expr);
				res[1] = new BlockASTLeaf(this.follow);
			}
			else
			{
				res[0] = new BlockASTLeaf(this.expr);
				res[1] = new BlockASTLeaf(this.instr);
			}
		}
		else
		{
			res[0] = new BlockASTLeaf(this.expr);
			res[1] = new BlockASTLeaf(this.instr);
			res[2] = new BlockASTLeaf(this.follow);
		}
		return (res);
	}
}
