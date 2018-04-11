package src.model.board;

public class TeleportCase extends Case
{
	private int xDest;
	private int yDest;
	private int stage;

	public TeleportCase(int x, int y, int xDest, int yDest, int stage)
	{
		super(x, y, TypeCase.TELEPORT);
		this.xDest = xDest;
		this.yDest = yDest;
		this.stage = stage;
	}

	public int getXDest()
	{
		return (this.xDest);
	}

	public int getYDest()
	{
		return (this.yDest);
	}

	public int getStage()
	{
		return (this.stage);
	}

	public TeleportCase clone()
	{
		return (new TeleportCase(this.x, this.y, this.xDest, this.yDest, this.stage));
	}

	public void setXDest(int x)
	{
		this.xDest = x;
	}

	public void setYDest(int y)
	{
		this.yDest = y;
	}

	public void setStage(int s)
	{
		this.stage = s;
	}

	public String toString()
	{
		return ("TeleportCase\n" + super.toString() + "xDest : " + this.xDest + "\nyDest : " + this.yDest + "\nStage : " + this.stage);
	}
}
