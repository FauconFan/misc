package src;

import javafx.application.Application;
import javafx.stage.Stage;

import src.model.MainLabyrinthe;

public class Main extends Application
{
	public static void main(String[] args)
	{
		launch(args);
	}

	@Override
	public void start(Stage primaryStage)
	{
		primaryStage.setTitle("Laby");
		primaryStage.show();
	}
}
