package src.model;

import src.model.Player;

import java.lang.Math;

public class CollisionsZManager
{
	private Player p;
	private float finalMove;
	private ContentMaze [] cms;
	private int highLevel;
	private boolean isFlyMode;


	public CollisionsZManager(Player p, boolean isFlyMode)
	{
		this.p         = p;
		this.isFlyMode = isFlyMode;
	}

	public void updateFloor(ContentMaze [] cms, int lvl)
	{
		this.cms       = cms;
		this.highLevel = lvl;
	}

	/**
	 * Renvoit le vecteur de déplacement
	 * @return finalMove
	 */
	public float getMove()
	{
		return (this.finalMove);
	}

	/**
	 * Renvoit la norme du vecteur déplacement
	 * @return Norme de finalMove
	 */
	public float getNorm()
	{
		return (this.finalMove);
	}

	/**
	 * Met à jour le vecteur de déplacement final en tenant compte des collisions avec le sol et le plafond
	 * @param dz Vecteur de déplacement (en z) souhaité
	 */
	public void updateMove(float dz)
	{
		if (isFlyMode && dz > 0 && this.p.getPosZ() + this.p.hitBoxTop + dz > highLevel + 1 && ((cms[2] != null && cms[2].isWall(this.p.getPosX(), this.p.getPosY(), this.p.hitBoxCircle)) || (cms[2] == null)))
		{
			this.finalMove = (highLevel + 1) - this.p.hitBoxTop - this.p.getPosZ();
		}
		else if (dz < 0 && this.p.getPosZ() - this.p.hitBoxBottom + dz <= highLevel && (this.isFloor(cms[1]) || (cms[0] != null && cms[0].isWall(this.p.getPosX(), this.p.getPosY(), this.p.hitBoxCircle))))
		{
			this.finalMove = (this.p.getPosZ() - this.p.hitBoxBottom + dz < highLevel) ? highLevel - (this.p.getPosZ() - this.p.hitBoxBottom) : dz;
		}
		else
		{
			this.finalMove = dz;
		}
	}

	/**
	 * Teste s'il y a un sol à la position du joueur
	 * @param cm Etage
	 * @return True si il y a un sol à cet étage à la position du joueur
	 */
	public boolean isFloor(ContentMaze cm)
	{
		return (cm.isFloor(this.p.getPosX(), this.p.getPosY()));
	}

	/**
	 * Teste si le joueur est sur un sol
	 * @return True si le joueur est sur un sol
	 */
	public boolean isOnFloor()
	{
		return (this.isFloor(cms[1]) && Math.abs(this.p.getPosZ() - this.p.hitBoxBottom - highLevel) < 10e-4);
	}
}
