package src.model.board;

public class JumpCase extends Case
{
	private float speed;

	public JumpCase(int x, int y, float val)
	{
		super(x, y, TypeCase.JUMP);
		this.speed = val;
	}

	public float getSpeed()
	{
		return (this.speed);
	}

	public JumpCase clone()
	{
		return (new JumpCase(this.x, this.y, this.speed));
	}

	public void setSpeed(float f)
	{
		this.speed = f;
	}

	public String toString()
	{
		return ("JumpCase\n" + super.toString() + "Speed : " + this.speed);
	}
}
