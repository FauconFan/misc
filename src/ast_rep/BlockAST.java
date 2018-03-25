package src.ast_rep;

public class BlockAST
{
	private final int x;
	private final int y;
	private final String name;

	public BlockAST(int x, int y, String name)
	{
		this.x = x;
		this.y = y;
		this.name = name;
	}

	public int getX()
	{
		return (this.x);
	}

	public int getY()
	{
		return (this.y);
	}

	public String getName()
	{
		return (this.name);
	}
}