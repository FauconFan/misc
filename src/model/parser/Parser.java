package src.model.parser;

import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.AlgoSample;
import src.model.MainMaze;
import src.view.View;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.Exception;

import com.google.gson.Gson;

import java.io.PrintWriter;

public class Parser
{
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

	/**
	 * Permet de charger un MainMaze
	 * @param file Le fichier
	 */
	public static MainMaze loadMaze(File file) throws IOException, ExtensionException
	{
		final String      path   = file.getPath();
		final SavesFormat format = checkExtension(path);

		if (format != null)
		{
			switch (format)
			{
			case serialized:
				ObjectInputStream ois = null;
				try{
					ois = new ObjectInputStream(new FileInputStream(path));
					return ((MainMaze)ois.readObject());
				} catch (final ClassNotFoundException e) {
					e.printStackTrace();
				} catch (final java.io.InvalidClassException e) {
					e.printStackTrace();
				}
				finally {
					if (ois != null)
					{
						ois.close();
					}
				}
				break;

			case json:
				try (BufferedReader br = new BufferedReader(new FileReader(path))) {
					String sCurrentLine;
					String text = "";
					while ((sCurrentLine = br.readLine()) != null)
					{
						text += sCurrentLine;
					}
					return ((new Gson()).fromJson(text, MainMaze.class));
				}
			}
			return (null);
		}
		else
		{
			throw new ExtensionException("ERROR: Incorrect extension (files must be on:\n" + SavesFormat.prettyPrint());
		}
	}

	/**
	 * Permet de sauvegarder un objet sérialisé ou au format JSON
	 * @param path Le chemin du fichier à sauvegader (l'extension sera ajoutée si elle n'est pas présente)
	 * @param format Le format de sauvegarde
	 * @param maze The maze
	 */
	public static void saveMaze(String path, SavesFormat format, MainMaze maze)
	{
		ObjectOutputStream oos = null;

		if (checkExtension(path) == null)
		{
			path += "." + format.name() + "." + EXTENSION;
		}
		switch (format)
		{
		case serialized:
			try {
				oos = new ObjectOutputStream(new FileOutputStream(path));
				oos.writeObject(maze);
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
			break;

		case json:
			try{ PrintWriter out = new PrintWriter(path);
				 out.println((new Gson()).toJson(maze));
				 out.close(); }
			catch (final java.io.FileNotFoundException e) {
				e.printStackTrace();
			}
			break;
		}
	}

	/** Get the extension format
	 * @param str The string
	 * @return The detected format or null
	 */
	private static SavesFormat checkExtension(String str)
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

	public static class ExtensionException extends Exception
	{
		public ExtensionException()
		{
			super();
		}

		public ExtensionException(String str)
		{
			super(str);
		}
	}
}
