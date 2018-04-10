package src.view;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Screen;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BackgroundImage;
import javafx.scene.layout.BackgroundPosition;
import javafx.scene.layout.BackgroundRepeat;
import javafx.scene.layout.BackgroundSize;
import javafx.stage.Screen;
import javafx.stage.Window;

public class Menu extends VBox
{
	protected Rectangle2D primaryScreenBounds;

	private static int screenWidth  = (int)Screen.getPrimary().getVisualBounds().getMaxX();
	private static int screenHeight = (int)Screen.getPrimary().getVisualBounds().getMaxY();

	public Menu()
	{
		super();
		setId("pane");


		setPadding(new Insets(10));
		setSpacing(15);
		setAlignment(Pos.CENTER);


		primaryScreenBounds = Screen.getPrimary().getVisualBounds();
		setPrefSize(primaryScreenBounds.getWidth(), primaryScreenBounds.getHeight());
	}

	protected Button addBigButton(String name)
	{
		Button b = new Button(name);

		b.setPrefWidth(screenWidth / 3);
		b.setPrefHeight(screenHeight / 15);

		getChildren().add(b);
		return (b);
	}

	protected Button addSmallButton(String name)
	{
		Button b = new Button(name);

		b.setPrefWidth(screenWidth / 10);
		b.setPrefHeight(screenHeight / 20);

		getChildren().add(b);
		return (b);
	}

	public void addButtonQuit()
	{
		Button b = addSmallButton("Quit");

		b.setOnAction(event->{
			Platform.exit();
		});
	}
}
