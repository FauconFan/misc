package src.controller;

import javafx.application.Application;
import javafx.stage.Stage;
import src.model.gen.Algo;
import src.model.gen.AlgoSample;
import src.model.MainMaze;
import src.view.View;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Controller extends Application
{
	private MainMaze maze;
	private final View view;

	public static String EXTENSION = ".maze";

	public Controller()
	{
		this.view = new View(this);
	}

	@Override
	public void start(Stage primaryStage)
	{
		primaryStage.setTitle("Laby");
		primaryStage.show();
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
	 * @param path Le chemin du fichier
	 */
	public void loadMaze(String path)
	{
		if (path.length() > EXTENSION.length() && path.substring(path.length() - EXTENSION.length(), path.length()).equals(EXTENSION))
		{
			ObjectInputStream ois = null;
			try{
				ois       = new ObjectInputStream(new FileInputStream(path));
				this.maze = (MainMaze)ois.readObject();
			} catch (final ClassNotFoundException e) {
				e.printStackTrace();
			} catch (final java.io.InvalidClassException e) {
				e.printStackTrace();
				//TODO DOSOMETHING
			}  catch (final java.io.IOException e) {
				e.printStackTrace();
				//TODO DOSOMETHING
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

	/** TEST
	 */
	public static void main(String[] args)
	{
		Controller con = new Controller();

		con.createMaze(new AlgoSample(), 30);
		con.saveMazeSerialized("./ser");
		con.loadMaze("./ser");
	}
}
