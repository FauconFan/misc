package src.model.board;

/**
 * Case du labyrinthe qui fait accélérer le joueur
 */
public class SpeedCase extends Case
{
	private float speedModif;
	private boolean activated = false;

	public SpeedCase(int x, int y, float val)
	{
		super(x, y, TypeCase.SPEED);
		this.speedModif = val;
	}

	/**
	 * Renvoit le coefficient d'accélération
	 * @return Coeffficient d'accélération
	 */
	public float getSpeedModif()
	{
		return (this.speedModif);
	}

	public SpeedCase clone()
	{
		return (new SpeedCase(this.x, this.y, this.speedModif));
	}

	/**
	 * Teste si la case a déjà été activée
	 * @return True si la case a déjà été activée
	 */
	public boolean isActivated()
	{
		return (this.activated);
	}

	/**
	 * Active la case
	 */
	public void activate()
	{
		activated = true;
	}

	/**
	 * Change le coefficient d'accélération
	 * @param f nouveau coefficient d'accélération
	 */
	public void setSpeedModif(float f)
	{
		this.speedModif = f;
	}

	public String toString()
	{
		return ("SpeedCase\n" + super.toString() + "Speed modification : " + this.speedModif + "\n");
	}
}
