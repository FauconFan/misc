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

import com.google.gson.Gson;

public class Controller
{
	private MainMaze maze;
	private View view;

	final static String EXTENSION = "maze";
	public static enum SavesFormat
	{
		serialized(), json();

		public static String prettyPrint()
		{
			String res="";

			for (SavesFormat s: values())
			{
				res += s.name() + EXTENSION;
			}
			return (res);
		}
	}

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
	 * Permet de charger un MainMaze
	 * @param file Le fichier
	 */
	public void loadMaze(File file)
	{
		String      path   = file.getPath();
		SavesFormat format = checkExtension(path);

		if (format != null)
		{
			ObjectInputStream ois = null;
			try{
				ois = new ObjectInputStream(new FileInputStream(path));
				if (format == SavesFormat.serialized)
				{
					this.maze = (MainMaze)ois.readObject();
				}
				else
				{
					Gson gson = new Gson();
					this.maze = gson.fromJson((String)ois.readObject(), MainMaze.class);
				}
			} catch (final ClassNotFoundException e) {
				this.view.setMsg("ERROR: " + e);
			} catch (final java.io.InvalidClassException e) {
				e.printStackTrace();
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
			this.view.setMsg("ERROR: Incorrect extension (files must be on:\n" + SavesFormat.prettyPrint());
		}
	}

	/**
	 * Permet de sauvegarder un objet sérialisé ou au format JSON
	 * @param path Le chemin du fichier à sauvegader (l'extension sera ajoutée si elle n'est pas présente)
	 * @param format Le format de sauvegarde
	 */
	public void saveMaze(String path, SavesFormat format)
	{
		ObjectOutputStream oos = null;

		if (checkExtension(path) == null)
		{
			path += "." + format.name() + "." + EXTENSION;
		}
		try {
			oos = new ObjectOutputStream(new FileOutputStream(path));
			switch (format)
			{
			case serialized:
				oos.writeObject(this.maze);
				break;

			case json:
				final Gson gson = new Gson();
				oos.writeObject(gson.toJson(this.maze));
			}
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

	/** Get the extension format
	 * @param str The string
	 * @return The detected format or null
	 */
	private SavesFormat checkExtension(String str)
	{
		for (SavesFormat s: SavesFormat.values())
		{
			String ext = "." + s.name() + "." + EXTENSION;
			if (str.length() > ext.length() && str.substring(str.length() - ext.length(), str.length()).equals(ext))
			{
				return (s);
			}
		}
		return (null);
	}
}
