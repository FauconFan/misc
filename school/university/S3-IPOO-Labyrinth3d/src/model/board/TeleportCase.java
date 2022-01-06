package src.model.board;

/**
 * Case du labyrinthe qui téléporte le joueur.
 */
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

	/**
	 * Renvoit la position en x de la destination de la case
	 * @return Position en x
	 */
	public int getXDest()
	{
		return (this.xDest);
	}

	/**
	 * Renvoit la position en y de la destination de la case
	 * @return Position en y
	 */
	public int getYDest()
	{
		return (this.yDest);
	}

	/**
	 * Renvoit l'étage de destination de la case
	 * @return Numéro d'étage
	 */
	public int getStage()
	{
		return (this.stage);
	}

	public TeleportCase clone()
	{
		return (new TeleportCase(this.x, this.y, this.xDest, this.yDest, this.stage));
	}

	/**
	 * Change la position en x de la destination de la case
	 * @param x Nouvelle position en x de destination
	 */
	public void setXDest(int x)
	{
		this.xDest = x;
	}

	/**
	 * Change la position en y de la destination de la case
	 * @param y Nouvelle position en y de destination
	 */
	public void setYDest(int y)
	{
		this.yDest = y;
	}

	/**
	 * Change le numéro d'étage de destination de la case
	 * @param s Nouveau numéro d'étage
	 */
	public void setStage(int s)
	{
		this.stage = s;
	}

	public String toString()
	{
		return ("TeleportCase\n" + super.toString() + "xDest : " + this.xDest + "\nyDest : " + this.yDest + "\nStage : " + this.stage + "\n");
	}
}
