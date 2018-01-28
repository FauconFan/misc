package src.controller;

import javafx.application.Application;
import javafx.stage.Stage;
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
}
