package src.view;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.layout.VBox;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.stage.FileChooser;
import javafx.stage.Screen;
import javafx.stage.Stage;

import java.io.File;

import src.controller.Controller;
import src.model.gen.Algo;

public class View
{
	private final Controller con;
	private Scene scene;
	public final Stage stage;

	public View(Stage stage, Controller con)
	{
		this.con   = con;
		this.scene = new ViewInMenu(this);
		this.stage = stage;

		stage.setTitle("Laby");

		stage.setScene(scene);
		stage.show();
	}

	public Scene getScene()
	{
		return (this.scene);
	}

	public void createMaze(Algo a, int c)
	{
		con.createMaze(a, c);
		con.showMaze(true);
		scene = new ViewIngame(this, con.getMaze());
		stage.setScene(scene);
		stage.show();
	}

	public void loadMaze(File f)
	{
		con.loadMaze(f);
	}

	public void setMsg(String s)
	{
		((ViewInMenu)this.scene).setMsg(s);
	}

	public void changeScene(Scene s)
	{
		stage.setScene(s);
		this.scene = s;
	}
}
