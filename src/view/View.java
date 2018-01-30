package src.view;

import src.controller.Controller;

import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.Parent;
public class View
{
	private final Controller con;
	private VBox view;

	public View(Controller con)
	{
		this.con  = con;
		this.view = new Menu();
	}

	public Parent asParent()
	{
		return (this.view);
	}
}
