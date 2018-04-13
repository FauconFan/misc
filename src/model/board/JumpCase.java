package src.model.board;

public class JumpCase extends Case
{
	private int nbLevelJump;

	public JumpCase(int x, int y, int value)
	{
		super(x, y, TypeCase.JUMP);
		this.nbLevelJump = value;
	}

	public int getNbLevelJump()
	{
		return (this.nbLevelJump);
	}

	public JumpCase clone()
	{
		return (new JumpCase(this.x, this.y, this.nbLevelJump));
	}

	public void setNbLevelJump(int f)
	{
		this.nbLevelJump = f;
	}

	public String toString()
	{
		return ("JumpCase\n" + super.toString() + "nbLevelJump : " + this.nbLevelJump + "\n");
	}
}
