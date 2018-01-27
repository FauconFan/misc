package src.model;

public class MainLabyrinthe
{
	private RectLabyrintheShift [] subLabyrinthes;
	private String name;
	private Player p;
	private int portee_vue;

	public MainLabyrinthe(String path)
	{
	}

	public MainLabyrinthe(Algo algo)
	{
	}

	public MainLabyrinthe(RectLabyrintheShift [] rls, String name)
	{
		this.name      = name;
		subLabyrinthes = rls;
	}

	public RectLabyrinthe getAdaptedLabyrinthe()
	{
		return (null);
	}

	private boolean canMove(int dx, int dy)
	{
		return (false);
	}

	public boolean movePlayer(int dx, int dy)
	{
		return (false);
	}
}
