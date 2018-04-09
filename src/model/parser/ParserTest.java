package src.model.parser;

import java.io.File;

import src.model.gen.Algo;
import src.model.gen.AlgoBackTracker;
import src.model.MainMaze;

public class ParserTest
{
	public static void main(String[] args)
	{
		MainMaze mm       = null;
		Algo     al       = null;
		String   notSaved = "";
		String   Saved    = "";

		try
		{
			al = new AlgoBackTracker(20, 50);
			mm = new MainMaze(al, false);
		}
		catch (Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}
		notSaved = mm.toString();
		System.out.println(notSaved);
		mm.displayMaze(true);
		try
		{
			File save = new File(".test.maze");
			Parser.saveMaze(".test", Parser.SavesFormat.gson, mm);
			mm = Parser.loadMaze(save);

			save.delete();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		Saved = mm.toString();
		System.out.println(Saved);
		mm.displayMaze(true);

		String res = "";
		if (notSaved.equals(Saved))
		{
			res = "ALL IS GOOD";
		}
		else
		{
			res = "SOMETHING IS DIFFERENT";
		}

		System.out.println("\n\n" + res);
		if (notSaved.equals(Saved) == false)
		{
			System.exit(1);
		}
	}
}
