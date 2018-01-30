package src.view;

import src.controller.Controller;

import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.Parent;

public class View
{
	private final Controller con;
	private GridPane view;

	public View(Controller con)
	{
		this.con = con;
		createView(15);
	}

	public Parent asParent()
	{
		return (this.view);
	}

	public void createView(int padding)
	{
		this.view = new GridPane();

		Label label = new Label("Hello the Maze");
		GridPane.setConstraints(label, 0, 0);

		Button buttonCreate = new Button("Create");
		Button buttonLoad   = new Button("Load");

		GridPane.setConstraints(buttonCreate, 0, 1);
		GridPane.setConstraints(buttonLoad, 0, 2);

		view.setPadding(new Insets(padding, padding, padding, padding));
		view.setHgap(padding);
		view.setVgap(padding);

		view.getChildren().addAll(label, buttonCreate, buttonLoad);
	}
}
