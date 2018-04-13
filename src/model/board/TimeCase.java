package src.model.board;

public class TimeCase extends Case
{
	private int timeNano;
	private boolean activated = false;

	public TimeCase(int x, int y, int val)
	{
		super(x, y, TypeCase.TIME);
		this.timeNano = val;
	}

	public int getTimeNano()
	{
		return (this.timeNano);
	}

	public TimeCase clone()
	{
		return (new TimeCase(this.x, this.y, this.timeNano));
	}

	public boolean isActivated()
	{
		return (this.activated);
	}

	public void activate()
	{
		activated = true;
	}

	public void setTimeNano(int l)
	{
		timeNano = l;
	}

	public String toString()
	{
		return ("TimeCase\n" + super.toString() + "Reduce time : " + this.timeNano + "\n");
	}
}
