package src.model.gen;

import src.model.MainLabyrinthe;
import src.model.RectLabyrintheShift;

public abstract class Algo
{
	public abstract RectLabyrintheShift[] buildSubLabyrinthe();

	public static void main(String[] args)
	{
		MainLabyrinthe ml;
		Algo           al;

		al = new AlgoSample();
		ml = new MainLabyrinthe(al, 0);
		System.out.print(ml);
	}
}
