package src.model.parser;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.MainMaze;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.lang.Exception;

import com.google.gson.*;

import java.io.PrintWriter;

/**
 * Parser for saving and loading mazes from the OS
 */
public class Parser
{
	final static String EXTENSION = "maze";

	public static enum SavesFormat
	{
		gson(),
		unknown();

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

	private static Gson buildGsonMaze()
	{
		return (new GsonBuilder()
				.registerTypeAdapter(Case.class, new Case.CaseAdapter())
				.registerTypeAdapter(LineWall.class, new LineWall.LineWallAdapter())
				.setPrettyPrinting()
				.create());
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
			case gson:
				try (BufferedReader br = new BufferedReader(new FileReader(path)))
				{
					Gson   gson;
					String sCurrentLine;
					String text = "";
					while ((sCurrentLine = br.readLine()) != null)
					{
						text += sCurrentLine;
					}
					gson = buildGsonMaze();
					return (gson.fromJson(text, MainMaze.class));
				}

			default:
				throw new ExtensionException();
			}
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
	public static void saveMaze(String path, SavesFormat format, MainMaze maze) throws ExtensionException
	{
		ObjectOutputStream oos = null;

		if (checkExtension(path) == null)
		{
			path += "." + EXTENSION;
		}
		switch (format)
		{
		case gson:
			try
			{
				PrintWriter out  = new PrintWriter(path);
				Gson        gson = buildGsonMaze();
				out.println(gson.toJson(maze));
				out.close();
			}
			catch (final java.io.FileNotFoundException e) {
				e.printStackTrace();
			}
			break;

		default:
			throw new ExtensionException();
		}
	}

	/** Get the extension format
	 * @param str The string
	 * @return The detected format or null
	 */
	public static SavesFormat checkExtension(String str)
	{
		for (SavesFormat s: SavesFormat.values())
		{
			String ext = "." + EXTENSION;
			if (str.length() > ext.length() && str.substring(str.length() - ext.length(), str.length()).equals(ext))
			{
				return (s);
			}
		}
		return (null);
	}

	public static class ExtensionException extends Exception
	{
		private static final long serialVersionUID = 0x4635999428371203L;

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
