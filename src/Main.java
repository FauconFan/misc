package src;

import src.controller.Controller;
import src.model.MainMaze;
import src.view.View;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application
{
	public static void main(String[] args)
	{
		launch();
	}

	@Override
	public void start(Stage primaryStage)
	{
		Controller c = new Controller();
		View       v = new View(c);

		c.initView(v);

		primaryStage.setTitle("Laby");

		Scene scene = new Scene(v.asParent(), 400, 400);
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
