package src.model.gen;

import src.model.gen.RectMazeShift;
import src.model.MainMaze;

public abstract class Algo
{
	public abstract RectMazeShift[] buildSubMaze();

	public static void main(String[] args)
	{
		MainMaze ml;
		Algo     al;

		al = new AlgoSample();
		ml = new MainMaze(al, 0);
		System.out.print(ml);
	}
}
