package src.controller;

import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.MainMaze;
import src.model.parser.Parser;
import src.view.View;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import com.google.gson.Gson;

import java.io.PrintWriter;

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
	 */
	public void createMaze(Algo algo)
	{
		try
		{
			this.maze = new MainMaze(algo);
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
