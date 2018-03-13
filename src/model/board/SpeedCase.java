package src.model.board;

public class SpeedCase extends Case
{
	private float speedModif;
	private boolean activated;

	public SpeedCase(int x, int y, float val, boolean b)
	{
		super(x, y);
		this.speedModif = val;
		this.activated  = b;
	}

	public float getSpeedModif()
	{
		return (this.speedModif);
	}

	public SpeedCase clone()
	{
		return (new SpeedCase(this.x, this.y, this.speedModif, this.activated));
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
		return ("SpeedCase\n" + super.toString() + "Speed modification : " + this.speedModif);
	}

	public TypeCase getTypeCase()
	{
		return (TypeCase.SPEED);
	}
}
