package src.model.board;

/**
 * Case du labyrinthe qui fait sauter le joueur d'un certain nombre d'étages.
 */
public class JumpCase extends Case
{
	private int nbLevelJump;

	public JumpCase(int x, int y, int value)
	{
		super(x, y, TypeCase.JUMP);
		this.nbLevelJump = value;
	}

	/**
	 * Renvoit le nombre d'étage a sauté
	 * @return Nombre d'étage
	 */
	public int getNbLevelJump()
	{
		return (this.nbLevelJump);
	}

	public JumpCase clone()
	{
		return (new JumpCase(this.x, this.y, this.nbLevelJump));
	}

	/**
	 * Change le nombre d'étage a sauté
	 * @param f nombre d'étage
	 */
	public void setNbLevelJump(int f)
	{
		this.nbLevelJump = f;
	}

	public String toString()
	{
		return ("JumpCase\n" + super.toString() + "nbLevelJump : " + this.nbLevelJump + "\n");
	}
}
