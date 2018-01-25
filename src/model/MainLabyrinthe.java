package src.model;

public class MainLabyrinthe {
	private final RectLabyrintheShift [] subLabyrinthes;
	private final String name;
	
	public MainLabyrinthe (String path){
		
	}

	public MainLabyrinthe (RectLabyrintheShift [] rls, String name){
		this.name = name;
		subLabyrinthes = rls;
	}
}
