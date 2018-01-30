package src.view;

import src.controller.Controller;

import javafx.scene.layout.GridPane;
import javafx.scene.Parent;

public class View
{
	private final Controller con;
	private GridPane view;

	public View(Controller con)
	{
		this.con = con;
		view     = new GridPane();
	}

	public Parent asParent()
	{
		return (this.view);
	}
}
