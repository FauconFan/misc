package src.controller;

import src.model.gen.Algo;
import src.model.MainMaze;
import src.model.parser.Parser;
import src.view.View;

import java.io.File;

/**
 * Le controleur
 */
public class Controller
{
	private MainMaze maze;
	private View view;

	public void initView(View v)
	{
		this.view = v;
	}

	/**
	 * Créer un labyrinthe avec les paramètres passés en arguments
	 * @param algo L'algorithme de création
	 * @param flyMode Est-on en flyMode ?
	 */
	public void createMaze(Algo algo, boolean flyMode)
	{
		try
		{
			this.maze = new MainMaze(algo, flyMode);
		}
		catch (Exception e)
		{
			e.printStackTrace();
			System.err.println("SNH");
			System.exit(1);
		}
	}

	/**
	 * Permet de charger un MainMaze
	 * @param file Le fichier
	 */
	public void loadMaze(File file) throws Exception
	{
		this.maze = Parser.loadMaze(file);
	}

	public void setMaze(MainMaze m)
	{
		this.maze = m;
	}

	/**
	 * Permet de sauvegarder un objet sérialisé ou au format JSON
	 * @param path Le chemin du fichier à sauvegader (l'extension sera ajoutée si elle n'est pas présente)
	 */
	public void saveMaze(String path)
	{
		try
		{
			Parser.saveMaze(path, Parser.SavesFormat.gson, this.maze);
		}
		catch (Parser.ExtensionException e)
		{
			e.printStackTrace();
		}
	}

	public MainMaze getMaze()
	{
		return (this.maze);
	}

	public void showMaze(boolean b)
	{
		this.maze.displayMaze(b);
	}
}
