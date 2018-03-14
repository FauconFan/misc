package src.model.board;

public class TimeCase extends Case
{
	private long timeMillis;
	private boolean activated;

	public TimeCase(int x, int y, long val, boolean b)
	{
		super(x, y);
		this.timeMillis = val;
		this.activated  = b;
	}

	public long getTimeMillis()
	{
		return (this.timeMillis);
	}

	public TimeCase clone()
	{
		return (new TimeCase(this.x, this.y, this.timeMillis, this.activated));
	}

	public boolean isActivated()
	{
		return (this.activated);
	}

	public void activate()
	{
		activated = true;
	}

	public String toString()
	{
		return ("TimeCase\n" + super.toString() + "Reduce time : " + this.timeMillis);
	}

	public TypeCase getTypeCase()
	{
		return (TypeCase.TIME);
	}
}
