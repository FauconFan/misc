package src.model.maps;

import src.model.gen.Algo;
import src.model.gen.ContentMazeFactory.GenFactoryException;

public class MapIntroBuilder
{
	public static Algo getMapIntro(int n) throws GenFactoryException
	{
		if (n == 1)
		{
			return (new MapIntro1());
		}
		else if (n == 2)
		{
			return (new MapIntro2());
		}
		else if (n == 3)
		{
			return (new MapIntro3());
		}
		else if (n == 4)
		{
			return (new MapIntro4());
		}
		else if (n == 5)
		{
			return (new MapIntro5());
		}
		else if (n == 6)
		{
			return (new MapIntro6());
		}
		else if (n == 7)
		{
			return (new MapIntro7());
		}
		return (new MapIntro1());
	}
}
