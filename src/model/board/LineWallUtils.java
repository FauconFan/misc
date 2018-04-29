package src.model.board;

import java.util.ArrayList;

/**
 * Classe utilitaires d'opérations élémentaires sur les murs (LineWall)
 */
public class LineWallUtils
{
	/**
	 * Permet d'avoir l'intersection entre 2 Linewalls
	 * Renvoie null, si il n'y a pas d'intersectop,
	 * @param  lw1 le 1er mur
	 * @param  lw2 le 2ème mur
	 * @return     une nouvelle instance de LineWall si intersection ou null
	 */
	public static LineWall intersection(LineWall lw1, LineWall lw2)
	{
		LineWall    lw;
		CoordsUtils cu;

		if (lw1 == null || lw2 == null)
		{
			return (null);
		}
		if (lw1.isHorizontal() != lw2.isHorizontal())
		{
			return (null);
		}
		cu = new CoordsUtils(lw1, lw2);
		if (cu.is_intersect())
		{
			return ((cu.mode)
					?   new LineWall(Math.max(cu.m1, cu.n1), lw1.getY1(), Math.min(cu.m2, cu.n2), lw1.getY1())
					:   new LineWall(lw1.getX1(), Math.max(cu.m1, cu.n1), lw1.getX1(), Math.min(cu.m2, cu.n2)));
		}
		return (null);
	}

	/**
	 * Permet d'obtenir une ArrayList contenant l'union de deux murs
	 * Ne renvoie qu'un seul mur si on peut représenter les deux murs avec qu'un seul mur
	 * @param  lw1 le 1er mur
	 * @param  lw2 le 2ème mur
	 * @return     une ArrayList de murs (de taille 1 ou 2)
	 */
	public static ArrayList <LineWall> union(LineWall lw1, LineWall lw2)
	{
		ArrayList <LineWall> res;
		CoordsUtils          cu;

		if (lw1 == null&& lw2 == null)
		{
			return (null);
		}
		res = new ArrayList <>();
		if (lw1 == null || lw2 == null)
		{
			res.add((lw1 == null) ? lw2 : lw1);
			return (res);
		}
		if (lw1.isHorizontal() != lw2.isHorizontal())
		{
			res.add(lw1);
			res.add(lw2);
			return (res);
		}
		cu = new CoordsUtils(lw1, lw2);
		if (cu.is_intersect())
		{
			res.add(cu.mode
					?   new LineWall(Math.min(cu.m1, cu.n1), lw1.getY1(), Math.max(cu.m2, cu.n2), lw1.getY1())
					:   new LineWall(lw1.getX1(), Math.min(cu.m1, cu.n1), lw1.getX1(), Math.max(cu.m2, cu.n2)));
			return (res);
		}
		res.add(lw1);
		res.add(lw2);
		return (res);
	}

	/**
	 * Permet d'obtenir une ArrayList de murs, désignant le premier mur privé du deuxième mur
	 * Si le deuxième mur n'a aucun mur en commun avec le premier mur, la fonction renvoie seulement le premier mur
	 * Renvoie une liste vide si lw1 = lw2.
	 * @param  lw1 le 1er mur
	 * @param  lw2 le 2ème mur
	 * @return     une ArrayList de murs (de taille 0, 1 ou 2)
	 */
	public static ArrayList <LineWall> except(LineWall lw1, LineWall lw2)
	{
		ArrayList <LineWall> res;
		CoordsUtils          cu;

		res = new ArrayList <>();
		if (lw2 == null)
		{
			res.add(lw1);
			return (res);
		}
		if (lw1.isHorizontal() != lw2.isHorizontal())
		{
			res.add(lw1);
			return (res);
		}
		cu = new CoordsUtils(lw1, lw2);
		if (cu.is_intersect())
		{
			if (cu.m1 < cu.n1)
			{
				res.add((cu.mode
						 ?   new LineWall(cu.m1, lw2.getY1(), cu.n1, lw2.getY1())
						 :   new LineWall(lw2.getX1(), cu.m1, lw2.getX1(), cu.n1)));
			}
			if (cu.m2 > cu.n2)
			{
				res.add(cu.mode
						?   new LineWall(cu.n2, lw2.getY1(), cu.m2, lw2.getY1())
						:   new LineWall(lw2.getX1(), cu.n2, lw2.getX1(), cu.m2));
			}
			return (res);
		}
		res.add(lw1);
		return (res);
	}

	/**
	 * Permet d'obtenir une ArrayList de murs, désignant le premier mur privé du deuxième mur si et seulement si le deuxième mur est compris dans le premier mur.
	 * Si le deuxième mur n'a aucun mur en commun avec le premier mur, la fonction renvoie seulement les deux murs
	 * Renvoie une liste vide si lw1 = lw2.
	 * @param  lw1 le 1er mur
	 * @param  lw2 le 2ème mur
	 * @return     une ArrayList de murs (de taille 0, 1 ou 2)
	 */
	public static ArrayList <LineWall> exceptIfIntersectOrUnion(LineWall lw1, LineWall lw2)
	{
		ArrayList <LineWall> res;
		CoordsUtils          cu;

		res = new ArrayList <>();
		if (lw1.onSameLine(lw2) == false)
		{
			res.add(lw1);
			res.add(lw2);
			return (res);
		}
		cu = new CoordsUtils(lw1, lw2);
		if (cu.is_intersect())
		{
			if (cu.m1 < cu.n1)
			{
				res.add((cu.mode
						 ?   new LineWall(cu.m1, lw2.getY1(), cu.n1, lw2.getY1())
						 :   new LineWall(lw2.getX1(), cu.m1, lw2.getX1(), cu.n1)));
			}
			if (cu.m2 > cu.n2)
			{
				res.add(cu.mode
						?   new LineWall(cu.n2, lw2.getY1(), cu.m2, lw2.getY1())
						:   new LineWall(lw2.getX1(), cu.n2, lw2.getX1(), cu.m2));
			}
			return (res);
		}
		res.add(lw1);
		res.add(lw2);
		return (res);
	}

	/**
	 * Sous class statique utilitaires pour les calculs d'intersection.
	 */
	private static class CoordsUtils
	{
		public boolean mode;
		public int m1;
		public int m2;
		public int n1;
		public int n2;

		/**
		 * Constructeur
		 * @param  lw1 1er mur
		 * @param  lw2 2ème mur
		 */
		public CoordsUtils(LineWall lw1, LineWall lw2)
		{
			this.mode = lw1.isHorizontal();
			if (mode)
			{
				this.m1 = lw1.getX1();
				this.m2 = lw1.getX2();
				this.n1 = lw2.getX1();
				this.n2 = lw2.getX2();
			}
			else
			{
				this.m1 = lw1.getY1();
				this.m2 = lw1.getY2();
				this.n1 = lw2.getY1();
				this.n2 = lw2.getY2();
			}
		}

		/**
		 * Si les deux murs données en paramètres au constructeur d'intersectent.
		 * @return true si intersection.
		 */
		public boolean is_intersect()
		{
			return ((m1 >= n1 && m1 < n2) ||
					(m2 > n1 && m2 <= n2) ||
					(n1 >= m1 && n1 < m2) ||
					(n2 > m1 && n2 <= m2));
		}
	}
}
