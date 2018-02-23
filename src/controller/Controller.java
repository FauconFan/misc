package src.controller;

import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.AlgoSample;
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
		this.maze = new MainMaze(algo);
	}

	/**
	 * Permet de charger un MainMaze
	 * @param file Le fichier
	 */
	public void loadMaze(File file)
	{
		try{
			this.maze = Parser.loadMaze(file);
		}
		catch (Exception e) {
			this.view.setMsg(e.toString());
		}
	}

	/**
	 * Permet de sauvegarder un objet sérialisé ou au format JSON
	 * @param path Le chemin du fichier à sauvegader (l'extension sera ajoutée si elle n'est pas présente)
	 * @param format Le format de sauvegarde
	 */
	public void saveMaze(String path, Parser.SavesFormat format)
	{
		try
		{
			Parser.saveMaze(path, format, this.maze);
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
