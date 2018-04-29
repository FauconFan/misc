package src.model.gen;

import src.model.ContentMaze;
import src.model.gen.MainMazeFactory.GenFactoryException;

/**
 * Classe Algo afin d'abstraire la génération de labyrinthe
 */
public abstract class Algo
{
	protected MainMazeFactory mmfactory;

	public Algo()
	{
		this.mmfactory = null;
	}

	public ContentMaze[] getContentMaze() throws GenFactoryException
	{
		ContentMaze[] content;

		if (this.mmfactory == null)
		{
			throw new RuntimeException("Should never happen. The maze should be generated");
		}
		content = this.mmfactory.buildContentMaze();
		return (content);
	}

	/**
	 * Main de test
	 * @param args args from cli
	 */
	public static void main(String[] args)
	{
		System.out.println("Nothing implemented in Algo....");
	}
}
