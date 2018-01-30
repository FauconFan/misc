package src.view;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.Parent;
import javafx.stage.Screen;

import src.controller.Controller;


public class View
{
	private final Controller con;
	private VBox view;

	public View(Controller con)
	{
		this.con  = con;
		this.view = new Menu(con);
	}

	public Parent asParent()
	{
		return (this.view);
	}

	public class Menu extends VBox
	{
		private final Controller con;
		public Menu(Controller con)
		{
			super();

			this.con = con;

			setPadding(new Insets(10));
			setSpacing(15);
			setAlignment(Pos.CENTER);

			Label label = new Label("Hello the Maze");

			Rectangle2D primaryScreenBounds = Screen.getPrimary().getVisualBounds();

			Button   buttonCreate = new Button("Create");
			Button   buttonLoad   = new Button("Load");
			Button[] buttons      = { buttonLoad, buttonCreate };
			for (Button b: buttons)
			{
				b.setPrefWidth(primaryScreenBounds.getWidth() / 1.5);
				b.setPrefHeight(primaryScreenBounds.getHeight() / 10);
			}

			buttonLoad.setOnAction(event->{
				//TODO POPUP to ask a path
				con.loadMaze("");
			});

			buttonCreate.setOnAction(event->{
				view = new MenuCreation();
				view.requestLayout();
				//TODO
			});


			getChildren().add(label);
			getChildren().add(buttonLoad);
			getChildren().add(buttonCreate);
		}
	}

	public class MenuCreation extends VBox
	{
	}
}
