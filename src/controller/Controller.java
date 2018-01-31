package src.controller;

import src.model.gen.Algo;
import src.model.gen.AlgoSample;
import src.model.MainMaze;
import src.view.View;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Controller
{
	private MainMaze maze;
	private View view;

	public static String EXTENSION = ".s.maze";

	public void initView(View v)
	{
		this.view = v;
	}

	/**
	 * Créer un labyrinthe avec les paramètres passés en arguments
	 * @param algo L'algorithme de création
	 * @param porteeVue La portée de la vue du joueur
	 */
	public void createMaze(Algo algo, int porteeVue)
	{
		this.maze = new MainMaze(algo, porteeVue);
	}

	/**
	 * Permet de charger un MainMaze (NE permet de charger pour l'instant qu'un objet sérialisé)
	 * @param file Le fichier
	 */
	public void loadMaze(File file)
	{
		String path = file.getPath();

		if (path.length() > EXTENSION.length() && path.substring(path.length() - EXTENSION.length(), path.length()).equals(EXTENSION))
		{
			ObjectInputStream ois = null;
			try{
				ois       = new ObjectInputStream(new FileInputStream(path));
				this.maze = (MainMaze)ois.readObject();
			} catch (final ClassNotFoundException e) {
				this.view.setMsg("ERROR: " + e);
			} catch (final java.io.InvalidClassException e) {
				e.printStackTrace();
				//TODO DOSOMETHING
			}  catch (final java.io.IOException e) {
				e.printStackTrace();
				this.view.setMsg("ERROR: IO Exception");
			}

			finally {
				try {
					if (ois != null)
					{
						ois.close();
					}
				} catch (final IOException ex) {
					ex.printStackTrace();
				}
			}
		}
		else
		{
			this.view.setMsg("ERROR: Incorrect extension (files must be on .s.maze or .h.maze)");
		}
	}

	/**
	 * Permet de sauvegarder un objet sérialisé
	 * @param path Le chemin du fichier à sauvegader (l'extension sera ajoutée si elle n'est pas présente)
	 */
	public void saveMazeSerialized(String path)
	{
		ObjectOutputStream oos = null;

		if (!(path.length() > EXTENSION.length() && path.substring(path.length() - EXTENSION.length(), path.length()).equals(EXTENSION)))
		{
			path += ".maze";
		}
		try {
			oos = new ObjectOutputStream(new FileOutputStream(path));
			oos.writeObject(this.maze);
			oos.flush();
		} catch (final java.io.IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (oos != null)
				{
					oos.flush();
					oos.close();
				}
			} catch (final IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}
