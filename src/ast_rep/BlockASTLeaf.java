package src.ast_rep;

import src.ast.ASTInterface;
import java.awt.Graphics2D;

public class BlockASTLeaf extends BlockAST
{
	private BlockAST parent;

	public BlockASTLeaf(ASTInterface asti)
	{
		super(0, 0, asti.getTag(), asti.getChilds());
		this.parent = null;
	}

	public BlockASTLeaf(String name)
	{
		super(0, 0, name, new BlockASTLeaf[0]);
		this.parent = null;
	}

	public void setParent(BlockAST parent)
	{
		if (this.parent != null)
		{
			throw new RuntimeException("Parent has already been initialised");
		}
		this.parent = parent;
	}
}
