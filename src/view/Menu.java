package src.view;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Screen;

public class Menu extends VBox
{
	public Menu(int padding)
	{
		super();
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

		getChildren().add(label);
		getChildren().add(buttonLoad);
		getChildren().add(buttonCreate);
	}
}
