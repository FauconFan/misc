package src.ast_rep;

import src.ast.AST;

public class BlockASTHead extends BlockAST
{
	public BlockASTHead(int x, int y, AST ast)
	{
		super(x, y, ast.getTag(), ast.getChilds());
	}
}
