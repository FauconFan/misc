package src.utils;

import java.util.ArrayList;
import java.util.Random;

/**
 * Stat Class
 *
 * Usefull to have some random values to generate a maze
 */
public class DiscreteStatMazeGenerator
{
	public static int[] getKParmiN(int k, int n)
	{
		ArrayList <Integer> content;
		int    nb_actu;
		int[]  res;
		Random ran;

		if (k > n || k == 0)
		{
			return (new int[0]);
		}
		content = new ArrayList <>();
		res     = new int[k];
		ran     = new Random();
		nb_actu = 0;
		for (int i = 1; i <= n; i++)
		{
			content.add(i);
		}
		while (nb_actu < k)
		{
			int nb = ran.nextInt(content.size());
			res[nb_actu] = content.get(nb);
			content.remove(nb);
			nb_actu++;
		}
		return (res);
	}
}
