package src.model.board;

public class TeleportCase extends Case
{
	private int xDest;
	private int yDest;

	public TeleportCase(int x, int y, int xDest, int yDest)
	{
		super(x, y);
		this.xDest = xDest;
		this.yDest = yDest;
	}

	public int getXDest()
	{
		return (xDest);
	}

	public int getYDest()
	{
		return (yDest);
	}

	public TeleportCase clone()
	{
		return (new TeleportCase(this.x, this.y, this.xDest, this.yDest));
	}

	public String toString()
	{
		return ("TeleportCase\n" + super.toString());
	}

	public TypeCase getTypeCase()
	{
		return (TypeCase.TELEPORT);
	}
}
