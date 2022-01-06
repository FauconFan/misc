package src.model.board;

/**
 * Case du labyrinthe qui donne un bonus de temps au joueur.
 */
public class TimeCase extends Case
{
	private int timeSec;
	private boolean activated = false;

	public TimeCase(int x, int y, int val)
	{
		super(x, y, TypeCase.TIME);
		this.timeSec = val;
	}

	/**
	 * Renvoit le nombre de secondes bonus
	 * @return Secondes
	 */
	public int getTimeSec()
	{
		return (this.timeSec);
	}

	public TimeCase clone()
	{
		return (new TimeCase(this.x, this.y, this.timeSec));
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
	 * Change le nombre de secondes bonus
	 * @param l Secondes bonus
	 */
	public void setTimeSec(int l)
	{
		timeSec = l;
	}

	public String toString()
	{
		return ("TimeCase\n" + super.toString() + "Reduce time : " + this.timeSec + "\n");
	}
}
