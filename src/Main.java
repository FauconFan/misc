package src;

import src.controller.Controller;
import src.model.MainMaze;
import src.view.View;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

import javafx.geometry.Rectangle2D;
import javafx.stage.Screen;

public class Main extends Application
{
	public static void main(String[] args)
	{
		launch();
	}

	@Override
	public void start(Stage primaryStage)
	{
		Rectangle2D primaryScreenBounds = Screen.getPrimary().getVisualBounds();

		primaryStage.setX(primaryScreenBounds.getMinX());
		primaryStage.setY(primaryScreenBounds.getMinY());
		primaryStage.setWidth(primaryScreenBounds.getWidth());
		primaryStage.setHeight(primaryScreenBounds.getHeight());

		Controller c = new Controller();
		View       v = new View(primaryStage, c);

		c.initView(v);
	}
}
