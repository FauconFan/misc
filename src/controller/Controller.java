package src.controller;

import javafx.application.Application;
import javafx.stage.Stage;
import src.model.gen.Algo;
import src.model.MainLabyrinthe;
import src.view.View;

public class Controller extends Application
{
	private MainLabyrinthe laby;
	private final View view;

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
	public void createLaby(Algo algo, int porteeVue)
	{
		this.laby = new MainLabyrinthe(algo, porteeVue);
	}
}
