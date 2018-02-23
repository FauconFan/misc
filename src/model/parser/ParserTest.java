package src.model.parser;

import java.io.File;

import src.model.gen.Algo;
import src.model.gen.AlgoBackTracker;
import src.model.MainMaze;

public class ParserTest
{
	public static void main(String[] args)
	{
		MainMaze mm;
		Algo     al;

		al = new AlgoBackTracker(20, 50);
		mm = new MainMaze(al);
		System.out.println(mm);
		mm.displayMaze(true);
		try
		{
			Parser.saveMaze(".test", Parser.SavesFormat.gson, mm);
			mm = Parser.loadMaze(new File(".test.gson.maze"));
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		System.out.println(mm);
		mm.displayMaze(true);
	}
}
